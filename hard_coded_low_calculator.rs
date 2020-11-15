/*convertor for 
     - Binary
     - Hexadecimal
     - Octal
     */
     
fn main() {
	//hard coded number
	
    let number = 1000;
    //binary
    print!("{}",format!("{:b}",number));
    //output - 1111101000
    
    //hexadecimal
    print!("\n{}",format!("{:x}",number));
    //output - 3e8
    
    //octal
    print!("\n{}", format!("{:o}",number));
    //output - 1750
     
 }
 
