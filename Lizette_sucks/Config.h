
/////////////////////////////////////////////////////////////
////////////               DEBUG             ////////////////
/////////////////////////////////////////////////////////////
#define LCD_DISPLAY
//#define OUTPUT_READABLE_YAWPITCHROLL
//#define OUTPUT_TEAPOT
//#define OUTPUT_READABLE_EULER
//#define COMPETITIVE_MODE
//#define PRINT_DISTANCE_TRAVELED
//#define PRINT_ANGLE
//#define WAIT_FOR_READY


/////////////////////////////////////////////////////////////
////////////              SETTING            ////////////////
/////////////////////////////////////////////////////////////
//Normal Mode Setting
#define FIRST_DISTANCE 6
#define TURN_ANGLE 85                    //+left
#define SECOND_DISTANCE 60
//#define THIRD_DISTANCE 6
#define LIMIT 12

//Competitive Mode Setting
#ifdef COMPETITIVE_MODE
#define PRINT_DISTANCE
#endif

//MPU6050_DMP5 Setting
#define INTERRUPT_PIN 2

//Servo_Motor Setting
#define TIME2SETTLE 20000
#define NEUTRAL_ANG 68
#define SERVO_PIN 3

//Reed Switch setting
#define REED_PIN 4
#define WHEEL_DIA 2.75591
#define NUMBER_OF_MAGNET 1

//Solenoid setting
#define SOLENOID_PIN 5
#define INTERVAL 700

//Button setting
#define BUTTON_PIN 6
#define TIME_START 15

//Ultrasonic sensor setting
#ifdef COMPETITIVE_MODE
#define ULTRA_SERVOPIN 6
#define trigPin 7
#define echoPin 8
#endif


