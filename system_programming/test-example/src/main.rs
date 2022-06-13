use std::process;

#[test]
fn test_if_process_returned(){
assert!(get_process_id() > 0);
}

fn main() {

println!("{}", get_process_id());
}

fn get_process_id() -> u32 {
  process::id()

}
