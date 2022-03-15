/*Value converter for 
     - Binary
     - Hexadecimal
     - Octal
     */
     
     fn to_binary(number:i64){
		 print!("The value in binary is:{}",format!("{:b}",number));	 
	 }
	 
	 fn to_octal(number:i64){
		 print!("\nThe value in octal is:{}",format!("{:o}",number));
	 }
	 
	 fn to_hexadecimal(number:i64){
		 print!("\nThe value in hexadecimal is:{}",format!("{:x}",number));
	 }
	 
fn main() {
	//test values
	to_binary(2000);
	to_octal(2000);
	to_hexadecimal(2000);    
 }
 
