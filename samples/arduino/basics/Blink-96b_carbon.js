// Copyright (c) 2016, Intel Corporation.

// Reimplementation of Arduino - Basics - Blink example
//   - Toggles an onboard LED on and off every second

// Hardware Requirements:
//   - None, to use the onboard LED
//   - Otherwise, an LED and a resistor (see basics/Blink.js for wiring info)

console.log("Starting Blink example...");

// import gpio module
var gpio = require("gpio");

var pin = gpio.open({
    pin: "GPIOA.15",
    direction: 'out'
});

// remember the current state of the LED
var toggle = false;

// schedule a function to run every 1s (1000ms)
setInterval(function () {
    toggle = !toggle;
    pin.write(toggle);
}, 1000);
