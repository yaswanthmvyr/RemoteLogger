# RemoteLogger

RemoteLogger wirelessly converts UART-equipped devices into Serial Monitors using ESP32, enabling remote monitoring and debugging via Wi-Fi.

## Disclaimer

This project builds upon other similar projects with following additions:
1. Complete application
2. Enhanced UI

## Getting Started

### Dependencies

- ESP32 Arduino Core - (latest)
- AsyncTCP - v1.1.1
- ESPAsyncWebServer - v1.2.3

### How to Install

Open `esp32_app.ino` file in ArduinoIDE.

Install the above library dependencies for library manager.

Download this repository and extract the .zip in Documents>Arduino>Libraries>{RemoteLogger}

## Features

- Uses Async Webserver for better performance
- Works on WebSockets
- Realtime logging
- Light weight
- Event driven

### Webpage enhancements

- Multiple Serial Monitor webpages can be opened simultaneously
- Timestamp
- Scroll lock
- Clear log
- Dark mode

### Upcoming Features
1. Buttons	
	1. Feel of the button
	2. Info for each button on hover
	3. Placement of buttons collide with scroller
2. Text box
	1. On sending data, clear it
	2. Save history on sending
	3. Options for hex, bin and other encoding
	4. Options for newline, CR, LF while sending
	5. Send data using enter and send button
3. Console
	1. Option to save the logs in a .txt file
4. Platform support
	1. Mobile, Tablet, desktop browsers

## Documentation

For better understanding of this project, start with `demo` in `examples` directory.

ESP32 has 2 main modes of operation:

- `STA`: Both ESP32 and browser machine are connected to the same network
- `AP`: ESP32 acts as an access point

## FAQ

1. When to use `print` and `println`?
   > `print` - simply prints the data sent over RemoteLogger without any newline character.
   > `println` - prints the data sent over RemoteLogger with a newline character.

2. How to access the webpage?
   > To Access RemoteLogger: Go to `<IP Address>/webserial` in your browser ( where `<IP Address>` is the IP of your ESP).


## Contributions

Every Contribution to this repository is highly appreciated! Don't fear to create pull requests which enhance or fix the library as ultimately you are going to help everybody.

## License

RemoteLogger is licensed under General Public License v3 ( GPLv3 ).
