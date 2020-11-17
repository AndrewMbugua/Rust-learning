fn main(){
     
   const MAX_POWER:u16 = 600;
   enum VehicleKind{
	   Motocycle,
	   Car,
	   Truck,
   };
   
   struct VehicleData{
	   kind: VehicleKind,
	   reg_year:u16,
	   reg_month:u8,
	   power:u16, 
   };
   
   let vehicle = VehicleData{
	   kind:VehicleKind::Car,
	   reg_year:2003,
	   reg_month:11,
	   power:120,
	   
   };
   if vehicle.power > MAX_POWER{println!("{}","Powerful car"); }
	
      
}
