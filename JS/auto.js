import { GlobalKeyboardListener } from "node-global-key-listener";
import { mouse, Button } from '@nut-tree/nut-js';

const v = new GlobalKeyboardListener();
let clicking = false;
let clickInterval;

console.log('Started listening.');

v.addListener(async (e, down) => {
    if (e.name == 'NUMPAD PLUS' && e.state == "DOWN") {
        console.log('numpad plus pressed.');
		
		clicking = !clicking;

        if (clicking) {
            console.log('Starting to click...');
            clickInterval = setInterval(async () => {
                await mouse.click(Button.LEFT);
            }, 28);
			
        } else {
            
			console.log('Stopped clicking.');
            if (clickInterval) clearInterval(clickInterval);
            
        }
    }
});
