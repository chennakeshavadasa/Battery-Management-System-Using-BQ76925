### BQ76925 PIN CONNECTIONS
- pin1 VCTL    -    Connected to Rbat and Cbat and shorted with pin2 BAT
- pin2 BAT     -    Shorted with pin1 VCTL
- pin3 VC6     -    No Connection
- pin4 VC5     -    No Connection
- pin5 VC4     -    No Connection
- pin6 VC3     -    Connected to Rin1 (which is connected to Battery1 positive terminal) and Cin1
- pin7 VC2     -    Connected to Rin2 (which is connected to Battery2 positive terminal) and Cin2
- pin8 VC1     -    Connected to Rin3 (which is connected to Battery3 positive terminal) and Cin3
- pin9 VC0     -    Connected to Rin4 (which is connected to Battery3 negative terminal) and Cin4
- pin10 VSS    -    GND 
- pin11 SENSEN -    Connected to Rsensen (which is connected to Battery3 negative terminal) and Csense (which is connected to pin12 SENSEP)
- pin12 SENSEP -    Connected to Rsensep (which is connected to Pack negative terminal) //needs to be edited edit
- pin13 ALERT  -    Connected to GPIO_ALERT 
- pin14 VIOUT  -    Connected to ADC3_CURRENT 
- pin15 VCOUT  -    Connected to Cvcout and ADC2_VOLTAGE
- pin16 VTB    -    Connected to Rth(which is connected to ADC_TEMP)
- pin17 VREF   -    Connected to Cref and Aref
- pin18 SDA    -    Connected to output SDA
- pin19 SCL    -    Connected to output SCL 
- pin20 V3P3   -    Connected to output V3P3

### ARDUINO PIN CONNECTIONS
- 5V  -  Connected to +5V
- GND  -  Common ground
- A0 -  VIOUT of BQ76925
- A1  -  VCOUT of BQ76925
- A2  -  VTB through RTH
- A4  -  SDA of BQ76925
- A5  -  SCL of BQ76925
- AREF - Vref of BQ76925
- D5  -  D5 of ESP
- D6  -  D6 of ESP
- D2  -  ALERT of BQ76925

### ESP8266 PIN CONNECTIONS
- GND  -  Common ground
- Vin  -  +5V
- D5  -  D5 of Arduino
- D6  -  D6 of Arduino
