use libc::c_char;
use std::{ffi::CString, fs};

#[no_mangle]
pub extern "C" fn rust_function(filepath: *const c_char) -> *const c_char{
    let file_path = unsafe { std::ffi::CStr::from_ptr(filepath as *const _).to_str().unwrap() };
    let file_contents = match fs::read_to_string(file_path) {
        Ok(content) => content,
        Err(err) => {
            eprintln!("Error reading file: {}", err);
            return std::ptr::null_mut();
        }
    };
    let c_string = CString::new(file_contents).unwrap();
    c_string.into_raw()
}
