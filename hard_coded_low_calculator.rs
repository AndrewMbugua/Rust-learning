/*convertor for 
     - Binary
     - Hexadecimal
     - Octal
     */
     
fn main() {
	//hard coded number
    let mut _num1: i16 = 100;
    let mut _num2: i16 = 500;
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
	
	//For the 1st portion
     print!("The binary format is:\n{}",format!("{:b} \n{:b}",_num1,_num2));
     print!("\nThe sum is:{}",(_num1 + _num2));
	//output 
	/*The binary format is:
         1100100 
         111110100
        The sum is:600
         */
     
 }
 
