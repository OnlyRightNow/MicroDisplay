/*
  This file contains HTML code for app of WiFi Message Board
*/

const String page PROGMEM = "<head>"
                            " <meta name='viewport' content='width=device-width, initial-scale=1.0'>"
                            " <link href='https://fonts.googleapis.com/css2?family=Roboto:wght@300&display=swap' rel='stylesheet'>"
                            " <style>"
                            " body{"
                            " background-color:white;"
                            " font-family: 'Roboto', sans-serif;"
                            "}"
                            "#tmm-logo{"
                            "  margin-top: 100px;"
                            "  margin-left: 50%;"
                            "  width:50%;"
                            "}"
                            "</style>"
                            " </head>"
                            " <body>"
                            " <h1>ESP32 WiFi Space Crash</h1>"
                            " <form action='/dataHandler' method='POST'>\r\n"
                            " <input type='submit' id='send' value='Send' />\r\n "
                            " </form> \r\n"
                            "</body>";
