use libc::c_int;
#[no_mangle]
pub unsafe extern "C" fn rust_function() -> i32 {
    42
}
