#include <asm-generic/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct addr_mask
{
    __u32 address;
    __u8 cidr_mask;
    __u32 binary_mask;
    __u32 network;
    __u32 broadcast;
    __u32 num_addresses;
};

/**
 * Error macro to print a message and return -1
 */
#define ERROR_RETURN(msg, ptr) ({ \
    printf("%s\n",msg);           \
    return -1;                  \
})

/**
 * Parse an address string with CIDR mask into a numeric structure
 * @param subnet - An IPv4 address string in the format xxx.xxx.xxx.xxx/yy
 * @returns A parsed address structure or NULL on invalid string
 */
int parse_address(struct addr_mask *res, char *subnet)
{
    // Allocate for 4 octets, we use __u32 here for ease when shifting
    __u32 octet[4] = {0};
    // Track which address octet we are on
    __u8 octet_num = 0;
    // Allocate for a return structure
    if(res == NULL)
        return -1;
    if(subnet == NULL)
        ERROR_RETURN("Address string was NULL", res);
    if(*subnet < '0' || *subnet > '9')
        ERROR_RETURN("Invalid address string, doesnt start numerically", res);
    while(*subnet != '\0') {
        if((*subnet < '0' || *subnet > '9') && *subnet != '.' && *subnet != '/')
            ERROR_RETURN("Address string was invalid", res);
        if(*subnet >= '0' && *subnet <= '9')
        {
            octet[octet_num] = (octet[octet_num] * 10) + (*subnet - '0');
            if(octet[octet_num] > 255)
                ERROR_RETURN("Invalid address string (had octet > 255)", res);
            subnet++;
            continue;
        }
        if(*subnet == '.')
        {
            octet_num++;
            if(octet_num >= 4)
                ERROR_RETURN("Invalid number of octets", res);
            subnet++;
            continue;
        }
        if(*subnet == '/' && octet_num != 3)
            ERROR_RETURN("Invalid address string, insufficient octets", res);
        if(*subnet == '/' && octet_num == 3)
            break;
    }
    res->address = (octet[0] << 24) | (octet[1] << 16) | (octet[2] << 8) | octet[3];
    if(*subnet == '/')
    {
        subnet++;
        while(*subnet != '\0')
        {
            if(*subnet < '0' || *subnet > '9')
                ERROR_RETURN("Invalid CIDR mask in address string", res);
            printf("Character was %c, cidr_mask was %u\n", *subnet, res->cidr_mask);
            res->cidr_mask = (res->cidr_mask * 10) + (*subnet - '0');
            printf("Character was %c, cidr_mask was %u\n", *subnet, res->cidr_mask);
            if(res->cidr_mask > 32)
                ERROR_RETURN("Invalid CIDR mask (> 32)", res);
            subnet++;
        }
    } else
        res->cidr_mask = 32;
    // Calculate the binary mask for the network
    // This uses a 1's complement of 0, then shifts off the bits not set in the mask
    res->binary_mask = ~0 << (32-res->cidr_mask);
    // The original IP address AND with the binary_mask = the network address
    res->network = res->address & res->binary_mask;
    res->num_addresses = (__u32)(~0) >> res->cidr_mask;
    // The broadcast address is the number of addresses in network + num of addresses in the
    // subnet
    res->broadcast = res->network + res->num_addresses;
    return 0;
}

int main()
{
    struct addr_mask addr = {0};
    if(parse_address (&addr, "10.20.30.25/24") != 0)
        return -1;
    printf ("Address: %08X\n",addr.address);
    printf("Binary mask: %08X\n",addr.binary_mask);
    printf("Network: %08X\n",addr.network);
    printf("Broadcast: %08X\n",addr.broadcast);
    printf("CIDR: %u\n",addr.cidr_mask);
}