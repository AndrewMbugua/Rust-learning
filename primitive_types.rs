fn main (){
	//primitive types
	
	let arr = [11,22,33];
	/*u size generates a unsigned/signed integer
	 that is going to be the same size as the memory 
	  address*/
	  
	let i: usize = 2;
	print!("{}", arr[i]);
	
	let i: isize = 2;
	print!("\n{}", arr[i]);
	
	//unsigned / signed
	let i: u32 = 2;
	print!("\n{}", arr[i]);
	
	let i: u64 = 2;
	print!("\n{}", arr[i]);



/*This code will generate three compilation errors, one for each call to print, except
the first one. Actually, only the usize type is allowed as an index of an array.
Similar error messages are printed if you use a vector instead of an array.
In such a way, Rust allows us to access arrays and vectors only in the most efficient way.
Notice that it is not allowed even to use an index of u32 type on a 32-bit system, nor
to use an index of u64 type on a 64-bit system. This guarantees source code portability.
For symmetry, there is also the isize type, which is a signed integer, having the same
size of a memory address in the target system.*/
	
}
