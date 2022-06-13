use std::process;

fn main() {

println!("{}", get_process_id());
}

fn get_process_id() -> u32 {
  process::id()

}
