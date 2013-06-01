Basic Push to Talk Demo
=======================

This program shows how to key the FT-817 radio's push to talk using a serial
port (CAT) command.

It is hardcoded for a 38400 baud serial port, the maximum speed of the FT-817.

To use it, plug a FT-817 into a serial port. On my machine, it comes up as
/dev/ttyUSB0 when using a USB to serial adaptor. Ensure you have permissions to
read and write to the serial port:

```
 $ make
 $ ./ptt /dev/ttyUSB0
```


Joel Stanley <joel@jms.id.au>
