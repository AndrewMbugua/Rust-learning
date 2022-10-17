struct lpm_tree *insert_tree_entry(struct lpm_tree *tree, __u32 address, __u8 mask, __u8 interface_number)
{
    // If the tree is NULL we can't do anything - so bail
    if(tree == NULL)
        return NULL;
    // We dont wanna play with the original pointer - so get a copy of it
    struct lpm_tree *current = tree;

    // We are working with ipv4 so CIDR mask cannot be > 32
    if(mask > 32)
        return NULL;

    // If mask == 24, then we need to test bits 0 -> 23
    // in order to place it on the correct place in the tree
    for(__u8 bit = 31-(32-mask); bit > 0; bit--)
    {
        // Shift the address right - so the right most bit == the bit being tested
        // then AND it with 1, erasing the other bits, if the result is 1
        // the bit was set, if not it wasnt
        if(((address >> bit) & 1) == 1)
        {
            // Check if the tree already has an entry at this bit position
            // if not - create one
            if(current->set_bit == NULL)
                current->set_bit = calloc(1, sizeof(struct lpm_tree));
            // Advance to the created position in the tree
            current = current->set_bit;
        } else
        {
            // Bit wasn't set - so do exactly as above but advancing down the 
            // unset branch
            if(current->unset_bit == NULL)
                current->unset_bit = calloc(1, sizeof(struct lpm_tree));
            current = current->unset_bit;
        }
    }
    // At this point we are at the end of the mask - set the interface number
    // and return the correct structure from the tree
    current->interface_number = interface_number;
    return current;
}