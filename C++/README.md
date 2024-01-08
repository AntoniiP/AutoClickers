# File contents:
## auto_multi_threading.cpp:
- Uses multithreading to simulate mouse clicks at a consistent interval, as defined by `CLICK_DELAY_MS` (you may change that variable depending on your needs). It listens for a key press `VK_ADD` (NumpadAdd) to start and stop clicking. The click function operates in a separate thread and toggles between simulating a mouse down and up event. There is a small delay in the main loop to reduce CPU usage.
- Delay of 28ms.
- Activation with Numpad Add key
