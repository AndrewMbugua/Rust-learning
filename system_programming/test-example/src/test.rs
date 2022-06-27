#[cfg(test)]

mod tests {
use super::get_process_id;

#[test]
fn test_if_id_is_returned() {
assert_ne!(get_process_id(), 0, "There is an error");

}


}
