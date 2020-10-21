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
                            " <h1>ESP32 WiFi Message Board</h1>"
                            " <p>Enter text and click Send</p>"
                            " <form action='/dataHandler' method='POST'>\r\n"
                            " <label for='message'>Message:</label> <input type='text' name='message' id='message'>""</p>\r\n"
                            " <input type='submit' id='send' value='Send' />\r\n "
                            " </form> \r\n"
                            " <img id='tmm-logo' src='https://lh3.googleusercontent.com/proxy/PyXx_oXF3T1GD0b8hq-ivAI5C104NQYEgyU-PeRGGHmB2HrwEEZQ5KerwLbxh5IHGC0mjdcIlWmR5mmK3_RcvIeNsuQ_2xEVtix0Gqjv-n_lCTUF3ckTl2PxuMRScH_mjMOVB8z_' />"
                            "</body>";
