class px700hdSensor : public PollingComponent,  public UARTDevice, public sensor::Sensor{
 public:
  px700hdSensor(UARTComponent *parent) : PollingComponent(1000), UARTDevice(parent) {}

  byte last[2];
  float value = 2;
  float lastPublished = -1;

  void setup() override {
    // This will be called by App.setup())
  }

  void loop() override {
    while (available()) {
      byte in = read();
      if(last[1] == 0x01 && last[0] == 0x18){
        value = 1;
      }
      else if(last[1] == 0x00 && last[0] == 0x17){
        value = 0;
      }
      else if(last[1] == 0x00 && last[0] == 0x14){
        value = 2;
      }
//      else {
//       value = 2;
//      }
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
