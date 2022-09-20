SEA:ME 2nd Project

> Before start
> - Before following this document, You must have to do first.
> - [Assemble Pi Racer & Move](https://github.com/SEA-ME/Team-Porsche-PiRacer)

# Table of Contents

# Basics knowledge of the Hardware
## What is CAN(Controller Arean Network)?
- Standard communication protocol designed for vehicles to communicate with each other within a vehicle
- **ECUs** in the vehicle communicate using the CAN protocol
### 장점
- Multi-Master
	- All nodes are bus masters and whenever the bus is empty they can send information 
- Twisted Pair Wire
	- Strong against electrical noise due to electrically differentiated communication using two lines : CAN_H, CAN_L
	- Scalability. Only need to connect to two lines, No matter how many ECUs. 
		<img width="444" alt="image" src="https://user-images.githubusercontent.com/54701846/191264465-e9e956a9-d0fc-4817-9e90-276ba66cf1e3.png">

- Message-Oriented Protocol
	- Use ID based on message priority. Use them to distinguish messages
	- Multiple messages come in at the same time, carry out the priority ID message 
> ECU
>	- Electronic control device used in a car

## What is Arduino?
- Micro Controller
	-  Small electronic device that can easily handle various movements such as read data from sensors or use data to control motors.
	- C language (or C++) and Arduino IDE enable simple coding
	- Consists of Regulator, Circuit Element, GPIO
	- Peripherals allow direct control of external devices
## What is Raspberry Pi?
- Micro Processor
	- Similar to Arduino, but called Processor because it can have various OSs
	- Unlike Arduino, there is no peripheral device and controls the device using an internal transistor
	- Powerful performance in computational processing, which is useful for complex computational processing such as video and graphics
