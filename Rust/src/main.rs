extern crate winapi;

use std::thread;
use std::time::Duration;
use winapi::um::winuser::{SendInput, INPUT, INPUT_MOUSE, MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_LEFTUP};
use winapi::um::winuser::{GetAsyncKeyState, VK_ADD};

fn main() {
    println!("AutoClicker started. Press NumpadAdd to toggle clicking on/off");
    let mut clicking = false;

    loop {
        // Listen for NumpadAdd key press to toggle clicking
        unsafe {
            if GetAsyncKeyState(VK_ADD as i32) & 1 == 1 {
                clicking = !clicking;
                if clicking {
                    println!("Clicking Started.");
                } else {
                    println!("Clicking Stopped.");
                }
            }
        }
        if clicking {
            unsafe {
                let mut input = INPUT {
                    type_: INPUT_MOUSE,
                    u: std::mem::zeroed(), // Use zeroed for unions
                };

                (*input.u.mi_mut()).dwFlags = MOUSEEVENTF_LEFTDOWN;
                SendInput(1, &mut input, std::mem::size_of::<INPUT>() as i32);
            
                (*input.u.mi_mut()).dwFlags = MOUSEEVENTF_LEFTUP;
                SendInput(1, &mut input, std::mem::size_of::<INPUT>() as i32);
            }
            thread::sleep(Duration::from_millis(28));
        } else {
            thread::sleep(Duration::from_millis(10));
        }
    }

}