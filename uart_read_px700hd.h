class px700hdSensor : public PollingComponent,  public UARTDevice, public sensor::Sensor{
 public:
  px700hdSensor(UARTComponent *parent) : PollingComponent(10000), UARTDevice(parent) {}

  byte last[9];
  float value = 3;
  float lastPublished = -1;

  void setup() override {
    // This will be called by App.setup())
  }

  void loop() override {
    while (available()) {
      byte in = read();
      if(last[8] == 0x05 && last[7] == 0x14 && last[6] == 0x00 && last[5] == 0x03 && last[4] == 0x00 && last[3] == 0x00 && last[2] == 0x00 && last[1] == 0x01 && last[0] == 0x18){
        value = 1;
      }
      else if(last[8] == 0x05 && last[7] == 0x14 && last[6] == 0x00 && last[5] == 0x03 && last[4] == 0x00 && last[3] == 0x00 && last[2] == 0x00 && last[1] == 0x00 && last[0] == 0x17){
        value = 0;
      }
//      else {
//       value = 2;
//      }
     last[8] = last[7];
     last[7] = last[6];
     last[6] = last[5];
     last[5] = last[4];
     last[4] = last[3];
     last[3] = last[2];
     last[2] = last[1];
     last[1] = last[0];
     last[0] = in;
     yield();
   }
  }

  void update() override {
    if(value != lastPublished) {
      publish_state(value);
      lastPublished = value;
    }
  }
};
