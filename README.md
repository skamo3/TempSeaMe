SEA:ME 2nd Project

> Before start
> - Before following this document, You must have to do first.
> - [Assemble Pi Racer & Move](https://github.com/SEA-ME/Team-Porsche-PiRacer)

# Table of Contents

# Basics knowledge of the Hardware
## What is CAN(Controller Arean Network)?
- 차량 내에서 자동차들이 서로 통신하기 위해 설계된 표준 통신 규격
- 차량 내 ECU(Elecronic Control Unit)들은 CAN 프로토콜을 이용해 통신
### 장점
- Multi-Master
	- 모든 노드가 버스마스터가 되어 버스가 비어있을 땐 언제든지 정보 송신 가능
- Twisted Pair Wire
	- CAN_H, CAN_L 두 개의 선을 이용해 전기적으로 차별되는 통신을 하기 때문에 전기적 노이즈에 강함
	- ECU가 아무리 많더라도 2가닥의 선에만 연결하면 되기 때문에 확장성이 좋음  
		<img width="444" alt="image" src="https://user-images.githubusercontent.com/54701846/191264465-e9e956a9-d0fc-4817-9e90-276ba66cf1e3.png">

- Message-Oriented Protocol
	- 메시지 우선 순위에 따라 ID를 할당하고, 이 ID를 이용해 메시지를 구별
	- 동시에 여러 개의 메시지가 들어오면 ID가 우선인 메시지를 우선적으로 처리
> ECU
>	- 자동차에서 사용되는 전자 제어 장치

## What is Arduino?
- Micro Controller
	- Bluetooth 모듈, Wifi 모듈, 적외선 센서, 초음파 센서 등 다양한 센서나 기기로 부터 정보를 입력받은 후 해당 정보들을 바탕으로 모터를 움직이거나 LED 조명을 켜고 끄는 등 **다양한 동작이 가능한 쉽게 다룰 수 있는 작은 전자기기** 
	- C언어(또는 C++)와 Arduino IDE를 통해 간단한 코딩으로 구현이 가능
	- Regulator, Circuit element, GPIO 로 구성됨
	- 주변 장치가 있어 외부기기를 직접 제어 가능
## What is Raspberry Pi?
- Micro Processor
	- 아두이노와 비슷하지만 다양한 OS를 탑재할 수 있어 Processor라고 부름
	- 아두이노와 다르게 주변 장치가 없고 내부 트랜지스터를 이용해 기기를 제어
	- 연산 처리에 있어 강력한 성능을 가지고 있어 비디오나 그래픽 등의 복잡한 연산 처리에 유용
