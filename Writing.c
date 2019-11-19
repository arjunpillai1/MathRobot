#include "PC_FileIO.c"
const float xMotorRadius=1.8;
const float xMotorConverter=2*PI*xMotorRadius/360;
const float yMotorRadius=1.8;
const float yMotorConverter=2*PI*yMotorRadius/360;
float currentX=0;
float currentY=0;

void tiltPen(bool direction){
	if(direction){
		//tilt up
		}else{
		//tilt down
	}
}

void moveX(int deltaX){
	nMotorEncoder[motorA]=0;
	if (deltaX>0){
		motor[motorA]=20;
		while (nMotorEncoder[motorA]<deltaX*xMotorConverter){}
		}else if (deltaX<0){
		motor[motorA]=-20;
		while (nMotorEncoder[motorA]>deltaX*xMotorConverter){}
	}
}

void moveY(int deltaY){
	nMotorEncoder[motorB]=0;
	if (deltaY>0){
		motor[motorB]=20;
		while (nMotorEncoder[motorB]<deltaY*yMotorConverter){}
		}else if (deltaY<0){
		motor[motorB]=-20;
		while (nMotorEncoder[motorB]>deltaY*yMotorConverter){}
	}
}

/*
void movePen(int x,int y){
	moveX(x-currentX);
	moveY(y-currentY);
}
*/

void writeCharacter(char character){
	//if (character==''){}
	if (character=='0'){
		//write 0
		tiltPen(0);
		moveX(1);
		moveY(-2);
		moveX(-1);
		moveY(2);
		//move to TR corner
		tiltPen(1);
		moveX(1);
	}

	if (character=='1'){
		//write 1
		tiltPen(0);
		moveY(-2);
		//move to TR corner
		tiltPen(1);
		moveY(2);
	}

	if (character=='2'){
		// write 2
		tiltPen(0);
		moveX(1);
		moveY(-1);
		moveX(-1);
		moveY(-1);
		moveX(1);
		//move to TR corner
		tiltPen(1);
		moveY(2);
	}

	if (character=='3'){
		//write 3
		tiltPen(0);
		moveX(1);
		moveY(-1);
		moveX(-1);
		moveX(1);
		moveY(-1);
		moveX(-1);
		//move to TR corner
		tiltPen(1);
		moveX(1);
		moveY(2);
	}

	if (character=='4'){
		//write 4
		tiltPen(0);
		moveY(-1);
		moveX(1);
		moveY(1);
		moveY(-2);
		//move to TR corner
		tiltPen(1);
		moveY(2);
	}

	if (character=='5'){
		//write 5
		tiltPen(0);
		moveX(1);
		moveX(-1);
		moveY(-1);
		moveX(1);
		moveY(-1);
		moveX(-1);
		//move to TR corner
		tiltPen(1);
		moveX(1);
		moveY(2);
	}

	if (character=='6'){
		//write 6
		tiltPen(0);
		moveX(1);
		moveX(-1);
		moveY(-2);
		moveX(1);
		moveY(1);
		moveX(-1);
		//move to TR corner
		tiltPen(1);
		moveX(1);
		moveY(1);
	}

	if (character=='7'){
		//write 7
		tiltPen(0);
		moveX(1);
		moveY(-2);
		//move to TR corner
		tiltPen(1);
		moveY(2);
	}

	if (character=='8'){
		//write 8
		tiltPen(0);
		moveX(1);
		moveY(-2);
		moveX(-1);
		moveY(2);
		moveY(-1);
		moveX(1);
		//move to TR corner
		tiltPen(1);
		moveY(1);
	}

	if (character=='9'){
		//write 9
		tiltPen(0);
		moveX(1);
		moveX(-1);
		moveY(-1);
		moveX(1);
		moveY(1);
		moveY(-2);
		moveX(-1);
		//move to TR corner
		tiltPen(1);
		moveX(1);
		moveY(2);
	}

	if (character=='.'){
		//figure out how to draw this
	}

	/* This might be removed cuz idk how to do diagonal unles it's like rapid switching/ or maybe like a zigzag thing
	if (character==','){
	moveY(-2) //to move to the lower corner
	tiltPen(0);
	moveY(-1
	}
	*/

	if (character=='+'){
		tiltPen(0);
		moveX(2);
		moveX(-1);
		moveY(1);
		moveY(-2);
		tiltPen(1);
	}

	if (character=='-'){
		tiltPen(0);
		moveX(2);
		tiltPen(1);
	}

	if (character=='='){
		tiltPen(0);
		moveX(2);
		tiltPen(1);
		moveX(-2);
		moveY(-1);
		tiltPen(0);
		moveX(2);
	}
	/*
	if (character=='x'){
		tiltPen(0);
		while(TL-BR diagonal){
			moveX(smallAmount);
			moveY(-smallAmount);
		}
		tiltPen(1);
		moveX(-2);
		tiltPen(0);
		while(BL-TR diagonal){
			moveX(smallAmount);
			moveY(smallAmount);
		}
	}
	*/

	if (character=='i'){
		tiltPen(0);
		moveY(-1);
		tiltPen(1);
		moveY(1.5);//idk like 1.5 or smth
		//do whatever i do to draw the decimal
	}
}

char stringToChar(string myString) {
	string temp = myString;
	stringDelete(myString, 0, 1);
	stringDelete(temp,1,19);// might be 19
	return (char *)&temp;
}


void writeSentence (string sol){
	for(int i=0;i<strlen(sol);i++){
		char movingChar=stringToChar(sol);
		writeCharacter(movingChar);
	}
}

task main(){
	displayString(3,"Hello");
	TFileHandle fin;
	bool fileOkay =false;
	fileOkay=openReadPC(fin,"Test.txt");
	if (!fileOkay)
		displayString(1,"XXXXX");
	string sol="";
	int line = 6;
	while (readTextPC(fin,sol)){
		displayString(line, sol);
		writeSentence(sol);
	}
	displayString(4,"End");
	while (!getButtonPress(buttonAny)){};
}
