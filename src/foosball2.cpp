/*
final3.cpp
Author: Lab Batch 37
One of the final programs for the Cs101 project FOOSBALL.
This includes a user interface comprising of a start screen, main menu containing options:
play,instructions,about,exit.
Instructions leads to a window giving instructions to play and score and a back button.
Exit closes the window.
About :credits
Play leads to the main game window:
Main game window consists of playfield,players,ball,scorecard and time display
it also contains two bitmaps Left and Right which on clicking,trigger a callback which moves the user players in the desired direction.
 
 
 
*/

#include<iostream>
#include "ezwin.h"
#include "circle.h"
#include "rect.h"
#include<time.h>
#include <cassert>
#include <cmath>
#include<cstdlib>
#include<string>
#include <sstream>
#include "bitmap.h"
using namespace std;


// Define  windows required
SimpleWindow W0("FOOSBALL!!", 11.5, 7.0, Position(1.0, 1.0));
SimpleWindow W1("Main Menu", 14.0, 5.0, Position(1.0, 1.0));
SimpleWindow foosballWindow("foosball", 20.0, 20.0, Position(3.0, 1.0));
SimpleWindow W3("Main*Menu", 15.0, 15.0, Position(1.0, 1.0));
SimpleWindow W4("Instructions", 28.0, 14.0, Position(1.0, 1.0));



// Define bitmap objects
BitMap aaa(W0);
BitMap MainMenu(W1);
BitMap Play(W1);
BitMap Instructions(W1);

BitMap Exit(W1);
BitMap as(W1);
BitMap Background(W4);
BitMap Info(W4);
BitMap Abt(W4);
BitMap Back(W4);

//string to store the score and time elapsed.they are converted using convert function of library sstream 
string scoreA,scoreB,timeval;
char c;
//increments for ball are posx and poxy
float posx=0.12,posy=+0.12;
//goalR and goalB are the global variables for storing goals by each team
int count,goalR=0,goalB=0;
char R,B;
//the following long int store the starting,current and elapsed time
long int tstart,tnow,telapsed;

Position p=Position(7.0,10.0);//sets the initial position of ball
	

Position q1(8.0,2.4);Position q2(4.0,6.0);Position q3(8.0,6.0);Position q4(12.0,6.0);Position q5(4.0,9.0);Position q6(8.0,9.0);Position q7(12.0,9.0);Position q8(4.0,11.0);Position q9(8.0,11.0);Position q10(12.0,11.0);Position q11(4.0,14.0); Position q12(8.0,14.0); Position q13(12.0,14.0);Position q14(8.0,17.6);//q1 to q14 are the player positions initialisation  

float pposxu=0.0,pposx=0.2,pposy=0.0;//postion incrementers are initialised(for movement) pposxu is for user and pposx is for the computer players
   

BitMap Left(foosballWindow);
BitMap Right(foosballWindow);//Declaration of Left, Right, and Stop bitmaps for the movement using callback
BitMap Stop(foosballWindow);

void fieldform();//Prototype of fieldform() function



//Function to move the user player.   
void MovePlayer1(Position &r,float pposxu,float pposy){
	RectangleShape R5(foosballWindow,r,Red,0.6,0.2);R5.ClearBorder();
	R5.Draw();
      	r=r+ Position(pposxu,pposy);
     	R5.Draw();
	}

//Function to move computer player
void MoveaiPlayer(Position &r,float pposx,float pposy){
	RectangleShape R5(foosballWindow,r,Blue,0.6,0.2);R5.ClearBorder();
        R5.Draw();
	r=r+ Position(pposx,pposy);	
	R5.Draw();
	}


// RunGame() is the function that controls the ball movement,generation of the field and invokes the respective functions for player movement 
void RunGame(Position &p,float posx, float posy){
	if(1){
		
		CircleShape C(foosballWindow,p,Yellow,0.2);C.ClearBorder();
		C.Draw();//Declaration of CircleShape object to represent ball
				
		MovePlayer1(q14,pposxu,pposy);
		MovePlayer1(q2,pposxu,pposy);MovePlayer1(q4,pposxu,pposy);		
		MovePlayer1(q8,pposxu,pposy);MovePlayer1(q10,pposxu,pposy);
	
	  	MoveaiPlayer(q1,pposx,pposy);MoveaiPlayer(q5,pposx,pposy);
		MoveaiPlayer(q7,pposx,pposy);MoveaiPlayer(q11,pposx,pposy);
		MoveaiPlayer(q13,pposx,pposy);

		MoveaiPlayer(q6,pposx,pposy);MoveaiPlayer(q12,pposx,pposy);

		MovePlayer1(q3,pposxu,pposy);MovePlayer1(q9,pposxu,pposy);
		//Movement of players
		
		
   		RectangleShape R8(foosballWindow,q8,Black,0.6,0.2);R8.ClearBorder();
		RectangleShape R9(foosballWindow,q9,Black,0.6,0.2);R9.ClearBorder();
		RectangleShape R10(foosballWindow,q10,Black,0.6,0.2);R10.ClearBorder();
                RectangleShape R1(foosballWindow,q1,Black,0.6,0.2);R1.ClearBorder();
		RectangleShape R2(foosballWindow,q2,Black,0.6,0.2);R2.ClearBorder();
		RectangleShape R3(foosballWindow,q3,Black,0.6,0.2);R3.ClearBorder();
		RectangleShape R4(foosballWindow,q4,Black,0.6,0.2);R4.ClearBorder();
		RectangleShape R5(foosballWindow,q5,Black,0.6,0.2);R5.ClearBorder();
		RectangleShape R6(foosballWindow,q6,Black,0.6,0.2);R6.ClearBorder();
		RectangleShape R7(foosballWindow,q7,Black,0.6,0.2);R7.ClearBorder();
		RectangleShape R11(foosballWindow,q11,Black,0.6,0.2);R11.ClearBorder();
		RectangleShape R12(foosballWindow,q12,Black,0.6,0.2);R12.ClearBorder();
		RectangleShape R13(foosballWindow,q13,Black,0.6,0.2);R13.ClearBorder();
		RectangleShape R14(foosballWindow,q14,Black,0.6,0.2);R14.ClearBorder();
		//Creation of RectangleShape objects for movement of players
		
		p = p+Position(posx,posy);//increments the position of ball by posx in xdirection and posy in ydirection
		usleep(100000);
                R1.Erase();
		R2.Erase();
		R3.Erase();R4.Erase();R5.Erase();R6.Erase();R7.Erase();R8.Erase();R9.Erase();R10.Erase();R11.Erase();R12.Erase();R13.Erase();
		fieldform();
       		C.Erase();
		//Erasing the above objects
	}
	CircleShape C(foosballWindow,p,Yellow,0.2);C.ClearBorder();C.Draw();//Recreating the ball.just for visibility of ball 
}



/*Mouse Click Callback of window foosballWindow
this is the callback function for the bitmaps Left and Right and Stop
Depending on the bitmap clicked,the callback resets the value of pposxu accordingly
*/
int MClick(const Position &p1){
	if(Left.IsInside(p1)){
		pposxu= -0.4;
	}
	else if(Right.IsInside(p1)){
		pposxu = 0.4;
	}
	else if(Stop.IsInside(p1)){
		pposxu = 0.0;
	}
	return 1;
}



//For movement of the ball when it enters the goal
void MoveBall1( Position &p,float posx, float posy){
	if(1){
		CircleShape C(foosballWindow,p,Yellow,0.2);C.ClearBorder();
		C.Draw();
       		C.Erase();
	}
	
}


	
/*function to print a message of goal if ball enter the goal given parameter as the name of the team 'R' or 'B'
Increments the global variable goalR or goalB depending on the case and updates the score on the screen
	function to display goal, take care of scorecard. It takes team as parameter
*/
int goaldisplay(char team){
     	
	foosballWindow.RenderText(Position(4.0,7.0), Position(12.0,13.0), "!!!GOAL!!!",Red);//it renders the text,"goal" at the centre of field
	//these coordinates are of top left corner and bottom right corner of the imaginary rectangle in which text will be displayed
	sleep(2.0);//till how much time we want the text to appear on screen
	/* we have decided that the  no. of goals scored to win the game is 2*/	
	
		if(team=='R'){goalR=goalR+1;}//if parameter passed is 'R' goal of team R is incremented by 1
		if(team=='B'){goalB=goalB+1;}//if parameter passed is 'B' goal of team B is incremented by 1
		if(1){
			//the next three lines are used for converting numeric entity goalR into string scoreA
			ostringstream convert;   // stream used for the conversion
			convert << goalR;      
			scoreA = convert.str(); 
			//center position of window is taken
			Position Center = foosballWindow.GetCenter();
			// Create bounding box for text
			Position UpperLeft = Center + Position(6.0,-5.5);
			Position LowerRight = Center + Position(10.0,-3.5);
			// Display the text
			foosballWindow.RenderText(UpperLeft, LowerRight,scoreA, Red);
		}
		
	
	if(1){ 
			ostringstream convert;  // stream used for the conversion
			convert << goalB;      // insert the textual representation of 'Number' in the characters in the stream
			scoreB = convert.str();
			Position Center = foosballWindow.GetCenter();
			// Create bounding box for text
			Position UpperLeft1 = Center + Position(4.0,-5.5);
			Position LowerRight1 = Center + Position(8.0,-3.5);
			// Display the text
			foosballWindow.RenderText(UpperLeft1, LowerRight1,scoreB, Red);
		}
		


			//if goal of any team becomes 4 the condition of this if becomes true
			if(goalR>1 || goalB>1){
				/* ostringstream convert is a part of sstream library it is the declaration of function convert*/
				ostringstream convert;
				//it renders the text,"match ends" at the centre of field when the goal of any team exceeds 4
				foosballWindow.RenderText(Position(4.0,7.0), Position(12.0,13.0), "!!!Match ends!!!",Red);sleep(2.0);
				//if goal of Team R is greater than B then user wins
				if(goalR>=goalB){
					//convert is a function to convert goalR into string and the string is stored in scoreA
					//this function is required as we can print only strings on window in EzWindows
					convert << goalR;  
					scoreA = convert.str();
					foosballWindow.RenderText(Position(4.0,7.0), Position(12.0,13.0), "!!!You win!!!",Red);sleep(2.0);
				}
		
				else{
		
					convert << goalB; 
					scoreB = convert.str();
					foosballWindow.RenderText(Position(4.0,7.0), Position(12.0,13.0), "!!!You lose!!!",Red);sleep(2.0);
				}
		//Below is the code used to print the outcome of the game
		foosballWindow.RenderText(Position(4.0,7.0), Position(12.0,13.0), "!!!Final score is!!!",Red);sleep(2.0);
		foosballWindow.RenderText(Position(2.0,5.0), Position(12.0,13.0), "!!!comp!!!",Red);sleep(1.0);
		foosballWindow.RenderText(Position(2.0,9.0), Position(12.0,13.0), scoreB,Red);sleep(1.0);
		foosballWindow.RenderText(Position(8.0,5.0), Position(12.0,13.0), "!!!Human!!!",Red);sleep(1.0);
		foosballWindow.RenderText(Position(8.0,9.0), Position(12.0,13.0), scoreA,Red);sleep(1.0);
		return -1;
	}	
	
	
}
	
	


//function for generation of field
void fieldform(){
	//foosballfield with border
 	foosballWindow.RenderRectangle(Position(2.0,2.0), Position(14.0,18.0),Green,true);
 	//D with border
 	foosballWindow.RenderRectangle(Position(4.0,2.0), Position(12.0,5.0),Green, true);
 	//D with border
 	foosballWindow.RenderRectangle(Position(4.0,15.0), Position(12.0,18.0),Green, true);
  	//goalpost with border
  	foosballWindow.RenderRectangle(Position(6.0,1.5), Position(10.0,2.0),Blue,true);
 	//goalpost with border
 	foosballWindow.RenderRectangle(Position(6.0,18.0), Position(10.0,18.5),Red,true);
	
	//central circle with border
	foosballWindow.RenderEllipse(Position(5.0,7.0),Position(11.0,13.0),Green,true);
 	//black center Line, thickness 0
 	foosballWindow.RenderLine(Position(2.0,10.0),Position(14,10.0),Black,0.0);
}



int g;//a variable that is required in the Loop() function



/*Loop() is the Timer callback function which executes every 5 milliseconds
Contents:
1.movement and collision conditions for the ball as well as players.
eg-ball collision with walls,different parts of the player
  -player movements when it is at the boundary
2.It also contains the AI of the game
3.Timer display which calculates the time elapsed in seconds and displays it.
*/
Position predicted(1.0,1.0);
int Loop(){
	
	RunGame(p,posx,posy);
	fieldform();
	

	//                                                         ****AI CODE****
	

/*        //\\          ||||||||||||||
         //  \\               --
        //    \\	      --	
       //******\\	      --
      //        \\	      --
     //          \\     ||||||||||||||      */







/*there are two cases-either the ball is moving towards the ai payers or they are moving away from the ai players(i.e. the ball is coming from behind them.the ai players respond to the ball differently in both cases .
the first case when the ball coming from behind is coded first.
the ai players move such that the players remain in line of the ball.as the ball moves to the right the ai players move to the right and as the ball moves to the left the ai players move to the left*/

  	
    	if (posy>0||p.GetYDistance()<2.4){                               //this is the condition to check the whether the ball is moving up or down 										(here it is down)
          	if (p.GetXDistance()<6.0){                               //following this we check the ball is in the line of which side of players 											(right ,mid or left
            		if (q11.GetXDistance()+0.2==p.GetXDistance()){   //this code is for right players
                		pposx=0.0;				 //+0.2 is added as we want the ball to hit at the corners of players  
            		}
            		else if (q11.GetXDistance()+0.2<p.GetXDistance()){//pposx is the increment in speed of ai players 
                		pposx=0.4;
            		}
            		else if (q11.GetXDistance()+0.2>p.GetXDistance()){
                		pposx=-0.4;
            		}   

       		}
        	else if (p.GetXDistance()>=6.0 && p.GetXDistance()<10.0){ //this code is for mid players
            		if (q12.GetXDistance()+0.2==p.GetXDistance()){
                		pposx=0.0;
            		}
            		else if (q12.GetXDistance()+0.2<p.GetXDistance()){
                		pposx=0.4;
            		}
            		else if (q12.GetXDistance()+0.2>p.GetXDistance()){
                		pposx=-0.4;
            		}   

        	}
        	else if (p.GetXDistance()>=10.0 && p.GetXDistance()<=14.0){//this code is for left players
            		if (q13.GetXDistance()+0.2==p.GetXDistance()){
                		pposx=0.0;
            		}
            		else if (q13.GetXDistance()+0.2<p.GetXDistance()){
                		pposx=0.4;
            		}
            		else if (q13.GetXDistance()+0.2>p.GetXDistance()){
                		pposx=-0.4;
            		}   

        	}

    	}

	else if(posy<0){		//this checks that the ball is moving in upward direction
		float m=posy/posx;	//it gives the slope of the velocity direction vector of the ball
		
		
		 if (p.GetYDistance()>=13.9){//this condition checks that the ball is below the attackers
		      	predicted.SetXDistance((p.GetYDistance()-14.0)/m+p.GetXDistance());
	
			/*the above calculates the predicted x distance but it could be negative
			as no wall collision is considered.so laws of reflection is used.*/

		        if(predicted.GetXDistance()<2.0)
		                 {predicted.SetXDistance(4.0-predicted.GetXDistance());/*simple reflection law is used.suppose the first formula gives 												predicted x coordinate of -1 then actually the ball wouldhave 												collided with the wall and have reached +5.0*/
		        }
		        else if(predicted.GetXDistance()>14.0)
		                 {predicted.SetXDistance(28.0-predicted.GetXDistance());//this is for collision with right vertical wall
	                }
			if (predicted.GetXDistance()>=10.0){   /*condition when ball is predicted to enter region of q13(right AI attacker*/
               			if (q13.GetXDistance()-0.2==predicted.GetXDistance()){ 
				        /*-0.2 reason---- we are taking left border of players middle block as reference so that they can hit the ball in 						direction towards the goal */
                        		pposx=0.0;//if the players left edge is at the predicted position then they do not move ie player is at the 								required position
                 		}
                		else if(q13.GetXDistance()-0.2>predicted.GetXDistance()){
        				/*condition when player lies to the right of predicted position of ball*/
                		         pposx=-0.4;//if it lies to the right they are moved by a distance 0.4 towards left
                		}
	               		 else if(q13.GetXDistance()-0.2<predicted.GetXDistance()){
	               		          pposx=0.4;//viceversa
	              	        }
        		 }

			/*the following code is for the ai attacker in the middle(q12).*/

          		else if (predicted.GetXDistance()<10.0 && predicted.GetXDistance()>=6.0){
                 
		                 if (q12.GetXDistance()==predicted.GetXDistance()){//we try to bring the mid ofthe player rectangle so that the middle 											player hits the ball in a straight direction
					pposx=0.0;
				 }
                 		 else if(q12.GetXDistance()>predicted.GetXDistance()){//if it lies to the right they are moved by a distance 0.2  												towards left
	                 	        pposx=-0.4;
		                 }        
   		                 else if (q12.GetXDistance()<predicted.GetXDistance()){//if it lies to the righ left they are moved by a distance 0.2 												towards right
                      			pposx=0.4;
			         }
         		 }
			/*the following code consists of the movement of players wrt left attacker(q11).*/

		         else if (predicted.GetXDistance()<6.0 && predicted.GetXDistance()>=2.0){
	        	         if (q11.GetXDistance()+0.2==predicted.GetXDistance()) {//here we try to bring the right edge of the player to hit the 												ball so that the ball goes in a direction towards the ball
	  	 	                pposx=0.0;
		                  }
		                else if(q11.GetXDistance()+0.2>predicted.GetXDistance()){//if it lies to the right they are moved by a distance 0.4 												towards left
	  	                        pposx=-0.4; 
		                  }
	  	                else if(q11.GetXDistance()+0.2<predicted.GetXDistance()){//if it lies to the righ left they are moved by a distance 													0.4 towards right
	  	                        pposx=0.4;
		                  }
		        }
		}
		/*the following consists of mid region.*/

		else if (p.GetYDistance()>=8.9 && p.GetYDistance()<13.9){//first it is checked that the ball lies between the mids and the attackers
        		predicted.SetXDistance((p.GetYDistance()-9.0)/m+p.GetXDistance());//in similar previous fashion predicted x coordinate of ball is 													found

        	        if(predicted.GetXDistance()<2.0){
        	        	 predicted.SetXDistance(4.0-predicted.GetXDistance());
			}
			else if(predicted.GetXDistance()>14.0){
       			          predicted.SetXDistance(28.0-predicted.GetXDistance());
			}
         		 /*now for right mid fielder(q7).*/

         		if (predicted.GetXDistance()>=10.0){
                 
         		         if (q7.GetXDistance()-0.2==predicted.GetXDistance()){
         		                pposx=0.0;
         		         }    
		                 else if(q7.GetXDistance()-0.2>predicted.GetXDistance()){
		                         pposx=-0.4;
		                 }
		                 else if(q7.GetXDistance()-0.2<predicted.GetXDistance()){
		                         pposx=0.4;
		                 }
		        }

			/*now for middle mid fielder(q6).*/

   		       else if (predicted.GetXDistance()<10.0 && predicted.GetXDistance()>=6.0){
   		                if (q6.GetXDistance()==predicted.GetXDistance()) {
        		        	pposx=0.0;
				}
                		else if(q6.GetXDistance()>predicted.GetXDistance()){
					pposx=-0.4;
                		}
                   		else if (q6.GetXDistance()<predicted.GetXDistance()){
                   			pposx=0.4;
                   		}      
                   	}
         		/*now for right midfielder(q5)*/

         		else if (predicted.GetXDistance()<6.0 && predicted.GetXDistance()>=2.0){
         			if (q5.GetXDistance()+0.2==predicted.GetXDistance()){
                			pposx=0.0;
                		}
				else if(q5.GetXDistance()+0.2>predicted.GetXDistance()){
                			pposx=-0.4;
                  		}     
                  		else if (q5.GetXDistance()+0.2<predicted.GetXDistance()){
                  			pposx=0.4;
                  		}
	    		}
		}
		/*now AI is written for goal keeper */

		 if (p.GetYDistance()<8.9 && p.GetYDistance()>=2.4){//this condition checks that the ball is between the goal keeper and mid fielders
  		predicted.SetXDistance((p.GetYDistance()-2.6)/m+p.GetXDistance());
	
        		if(predicted.GetXDistance()<2.0)
        		         predicted.SetXDistance(4.0-predicted.GetXDistance());

        		else if(predicted.GetXDistance()>14.0)
        		         predicted.SetXDistance(28.0-predicted.GetXDistance());

			if (q1.GetXDistance()==predicted.GetXDistance()){
        			pposx=0.0;
        		}            
         		else if (q1.GetXDistance()>predicted.GetXDistance()){
        			pposx=-0.4;
        		}
        		else if (q1.GetXDistance()<predicted.GetXDistance()){
        			pposx=0.4;
        		}               
		}                           
        }            











// **AI ends**






//                                                              **********COLLISIONS**********

/* this is the function to reflect the ball from player. This particular function is for first player. It first checks that if the difference 		between absolute values of ycoordinate of ball and ycoordinate of the player is less than 0.2(radius of ball + half the player's width), then 		check where the ball hits(right part, middle part or the left part and accordingly the conditions are executed(posx and posy, the incrementors 		of ball in x direction and y direction are changed. this function does not account for back pass. The player hits ball only in the direction of 	his goal no matter from where the ball is coming. If absolute difference between the ycoordinates is exactly 0.2, different incrementors are 		initialised*/
	//for first player
	if(abs(p.GetYDistance()-q1.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q1.GetXDistance()-0.1) && p.GetXDistance()<=(q1.GetXDistance()+0.1)){
			posx=0.1;posy=0.4;
		}
		if(p.GetXDistance()>=(q1.GetXDistance()-0.35) && p.GetXDistance()<(q1.GetXDistance()-0.1)){
			posx=-0.3;posy=0.3;
		}
		if(p.GetXDistance()>(q1.GetXDistance()+0.1) && p.GetXDistance()<=(q1.GetXDistance()+0.35)){
			posx=0.3;posy=0.3;
		}

	}
	if(abs(p.GetYDistance()-q1.GetYDistance())==0.2){posx=-0.3;posy=0.3;}
	//code ends for first player
	//code for second player
	if(abs(p.GetYDistance()-q2.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q2.GetXDistance()-0.1) && p.GetXDistance()<=(q2.GetXDistance()+0.1)){
			posx=0.2;posy=-0.4;
		}
		if(p.GetXDistance()>=(q2.GetXDistance()-0.5) && p.GetXDistance()<(q2.GetXDistance()-0.1)){
			posx=-0.4;posy=-0.2;
		}
		if(p.GetXDistance()>(q2.GetXDistance()+0.1) && p.GetXDistance()<=(q2.GetXDistance()+0.5)){
			posx=0.4;posy=-0.2;
		}

	}
	if(abs(p.GetYDistance()-q2.GetYDistance())==0.2){posx=0.3;posy=-0.3;}
	//code ends for second player	
	//code for third player

	if(abs(p.GetYDistance()-q3.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q3.GetXDistance()-0.1) && p.GetXDistance()<=(q3.GetXDistance()+0.1)){
			posx=0.2;posy=-0.4;
		}
		if(p.GetXDistance()>=(q3.GetXDistance()-0.5) && p.GetXDistance()<(q3.GetXDistance()-0.1)){
			posx=-0.4;posy=-0.2;
		}
		if(p.GetXDistance()>(q3.GetXDistance()+0.1) && p.GetXDistance()<=(q3.GetXDistance()+0.5)){
			posx=0.4;posy=-0.2;
		}

	}
	if(abs(p.GetYDistance()-q3.GetYDistance())==0.2){posx=0.3;posy=-0.3;}
	//code ends for third player
	if(abs(p.GetYDistance()-q4.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q4.GetXDistance()-0.1) && p.GetXDistance()<=(q4.GetXDistance()+0.1)){
			posx=0.2;posy=-0.4;
		}
		else if(p.GetXDistance()>=(q4.GetXDistance()-0.5) && p.GetXDistance()<(q4.GetXDistance()-0.1)){
			posx=-0.4;posy=-0.2;
		}
		else if(p.GetXDistance()>(q4.GetXDistance()+0.1) && p.GetXDistance()<=(q4.GetXDistance()+0.5)){
			posx=0.4;posy=-0.2;
		}
	}
	if(abs(p.GetYDistance()-q4.GetYDistance())==0.2){posx=0.3;posy=-0.3;}
	//code ends for fourth player	
	if(abs(p.GetYDistance()-q5.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q5.GetXDistance()-0.1) && p.GetXDistance()<=(q5.GetXDistance()+0.1)){
			posx=0.1;posy=0.4;
		}
		else if(p.GetXDistance()>=(q5.GetXDistance()-0.5) && p.GetXDistance()<(q5.GetXDistance()-0.1)){
			posx=-0.3;posy=0.4;
		}
		else if(p.GetXDistance()>(q5.GetXDistance()+0.1) && p.GetXDistance()<=(q5.GetXDistance()+0.5)){	
			posx=0.3;posy=0.4;
		}
	}
	if(abs(p.GetYDistance()-q5.GetYDistance())==0.2){posx=-0.3;posy=0.3;}
	//code ends for fifth player
	if(abs(p.GetYDistance()-q6.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q6.GetXDistance()-0.1) && p.GetXDistance()<=(q6.GetXDistance()+0.1)){
			posx=0.1;posy=0.4;
		}
		else if(p.GetXDistance()>=(q6.GetXDistance()-0.5) && p.GetXDistance()<(q6.GetXDistance()-0.1)){
			posx=-0.3;posy=0.4;
		}
 		else if(p.GetXDistance()>(q6.GetXDistance()+0.1) && p.GetXDistance()<=(q6.GetXDistance()+0.5)){
			posx=0.3;posy=0.4;
		}
	}
	if(abs(p.GetYDistance()-q6.GetYDistance())==0.2){posx=-0.3;posy=0.3;}
	//code end for sixth player
	if(abs(p.GetYDistance()-q7.GetYDistance())<0.1){
		if(p.GetXDistance()>=(q7.GetXDistance()-0.1) && p.GetXDistance()<=(q7.GetXDistance()+0.1)){
			posx=0.1;posy=0.4;
		}
		else if(p.GetXDistance()>=(q7.GetXDistance()-0.5) && p.GetXDistance()<(q7.GetXDistance()-0.1)){
			posx=-0.3;posy=0.3;
		}
		else if(p.GetXDistance()>(q7.GetXDistance()+0.1) && p.GetXDistance()<=(q7.GetXDistance()+0.5)){
			posx=0.3;posy=0.3;
		}
	}
	if(abs(p.GetYDistance()-q7.GetYDistance())==0.2){posx=-0.3;posy=0.3;}
	//code ends for seventh player
	if(abs(p.GetYDistance()-q8.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q8.GetXDistance()-0.1) && p.GetXDistance()<=(q8.GetXDistance()+0.1)){
			posx=0.1;posy=-0.4;
		}
		if(p.GetXDistance()>=(q8.GetXDistance()-0.5) && p.GetXDistance()<(q8.GetXDistance()-0.1)){
			posx=-0.3;posy=-0.4;
		}
		if(p.GetXDistance()>(q8.GetXDistance()+0.1) && p.GetXDistance()<=(q8.GetXDistance()+0.5)){
			posx=0.3;posy=-0.4;
		}
	}
	if(abs(p.GetYDistance()-q8.GetYDistance())==0.2){posx=-0.3;posy=-0.3;}	
	//ends for eight player
	if(abs(p.GetYDistance()-q9.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q9.GetXDistance()-0.1) && p.GetXDistance()<=(q9.GetXDistance()+0.1)){
			posx=0.1;posy=-0.4;
		}
		if(p.GetXDistance()>=(q9.GetXDistance()-0.5) && p.GetXDistance()<(q9.GetXDistance()-0.1)){
			posx=-0.3;posy=-0.3;
		}
		if(p.GetXDistance()>(q9.GetXDistance()+0.1) && p.GetXDistance()<=(q9.GetXDistance()+0.5)){
			posx=0.3;posy=-0.3;
		}
	}
	if(abs(p.GetYDistance()-q9.GetYDistance())==0.2){posx=-0.3;posy=-0.3;}
	//ends for ninth player
	if(abs(p.GetYDistance()-q10.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q10.GetXDistance()-0.1) && p.GetXDistance()<=(q10.GetXDistance()+0.1)){
			posx=0.1;posy=-0.4;
		}
		if(p.GetXDistance()>=(q10.GetXDistance()-0.5) && p.GetXDistance()<(q10.GetXDistance()-0.1)){
			posx=-0.3;posy=-0.3;
		}
		if(p.GetXDistance()>(q10.GetXDistance()+0.1) && p.GetXDistance()<=(q10.GetXDistance()+0.5)){
			posx=0.3;posy=-0.3;
		}
	}
	if(abs(p.GetYDistance()-q10.GetYDistance())==0.2){posx=-0.3;posy=-0.3;}
	//ends for tenth player
	if(abs(p.GetYDistance()-q11.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q11.GetXDistance()-0.1) && p.GetXDistance()<=(q11.GetXDistance()+0.1)){
			posx=0.2;posy=0.4;
		}
	 	if(p.GetXDistance()>=(q11.GetXDistance()-0.5) && p.GetXDistance()<(q11.GetXDistance()-0.1)){
			posx=-0.4;posy=0.2;
		}
		if(p.GetXDistance()>(q11.GetXDistance()+0.1) && p.GetXDistance()<=(q11.GetXDistance()+0.5)){
			posx=0.4;posy=0.2;
		}
	}
	if(abs(p.GetYDistance()-q11.GetYDistance())==0.2){posx=-0.3;posy=0.3;}	
	//ends for eleventh player
	if(abs(p.GetYDistance()-q12.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q12.GetXDistance()-0.1) && p.GetXDistance()<=(q12.GetXDistance()+0.1)){
			posx=0.2;posy=0.4;
		}
		if(p.GetXDistance()>=(q12.GetXDistance()-0.5) && p.GetXDistance()<(q12.GetXDistance()-0.1)){
			posx=-0.4;posy=0.2;
		}
		if(p.GetXDistance()>(q12.GetXDistance()+0.1) && p.GetXDistance()<=(q12.GetXDistance()+0.5)){
			posx=0.4;posy=0.2;
		}
	}
	if(abs(p.GetYDistance()-q12.GetYDistance())==0.2){posx=-0.3;posy=0.3;}	
	//ends for twelth player
	if(abs(p.GetYDistance()-q13.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q13.GetXDistance()-0.1) && p.GetXDistance()<=(q13.GetXDistance()+0.1)){
			posx=0.2;posy=0.4;
		}
		if(p.GetXDistance()>=(q13.GetXDistance()-0.5) && p.GetXDistance()<(q13.GetXDistance()-0.1)){
			posx=0.4;posy=0.2;
		}
		if(p.GetXDistance()>(q13.GetXDistance()+0.1) && p.GetXDistance()<=(q13.GetXDistance()+0.5)){
			posx=0.4;posy=0.2;
		}
	}
	if(abs(p.GetYDistance()-q13.GetYDistance())==0.2){posx=+0.3;posy=0.3;}	
	//ends for thirteenth player
	if(abs(p.GetYDistance()-q14.GetYDistance())<0.2){
		if(p.GetXDistance()>=(q14.GetXDistance()-0.1) && p.GetXDistance()<=(q14.GetXDistance()+0.1)){
			posx=0.1;posy=-0.4;
		}
		if(p.GetXDistance()>=(q14.GetXDistance()-0.5) && p.GetXDistance()<(q14.GetXDistance()-0.1)){
			posx=0.3;posy=-0.3;
		}
		if(p.GetXDistance()>(q14.GetXDistance()+0.1) && p.GetXDistance()<=(q14.GetXDistance()+0.5)){
			posx=0.3;posy=-0.3;
		}
	}
	if(abs(p.GetYDistance()-q14.GetYDistance())==0.2){posx=+0.3;posy=-0.3;}
	//ends for fourteenth player
	
	// Next 12 lines are the code to change the sign of the position increments of the player when it reaches the boundaries of the field	
	if(q11.GetXDistance()<=2.4){
		pposx=0.4;
	}
	else if(q13.GetXDistance()>=13.6){
		pposx=-0.4;
	}
	if(q2.GetXDistance()<=2.4){
		pposxu=0.4;
	}
	else if(q4.GetXDistance()>=13.6){
		pposxu=-0.4;
	}


	if(p.GetXDistance()>5.9 && p.GetXDistance()<10.1 ){//Conditions given if ball enters any goal
		if(p.GetYDistance()>1.8 && p.GetYDistance()<2.1){//same as above comment	
			MoveBall1(p,posx,posy);//new function to erase the ball as it reaches the goal
			g=goaldisplay('R');// display the text
			if(g==-1){//if g=-1 i.e. either player has scored 2 goals the foosballWindow closes
				foosballWindow.Close();
				
				return -1;
			}					
			else{//if neither player has scored 2 goals, the position of the ball is reset to a random x coordinate on the center line
				p.SetXDistance(3+rand()%10);//reseting the x-coordinate
				p.SetYDistance(10.0);//reseting the y-coordinate
				posx=0.2,posy=-0.2;//reseting posx and posy
			}
		}
		if(p.GetYDistance()>17.8 && p.GetYDistance()<18.1){					
			MoveBall1(p,posx,posy);
			g=goaldisplay('B');
			if(g==-1){
				foosballWindow.Close();
				
				return -1;
			}
			else{
				p.SetXDistance(3+rand()%10);
				p.SetYDistance(10.0);
				posx=0.2,posy=-0.2;
			}
		
		}
	}
	else{		 
		if(p.GetXDistance()>13.7 || p.GetXDistance()<2.3){//if ball hits any vertical wall
			posx=-posx;	//x direction of ball is changed
		}
		if(p.GetYDistance()>17.7 || p.GetYDistance()<2.3){//if ball hits any horizontal wall
			posy=-posy; 	//y direction of ball is changed
		}
	}

	
	//Get the current time using GetMilliseconds function and calculate the time elapsed
	tnow=GetMilliseconds();	
	telapsed=tnow-tstart;telapsed/=1000;
	ostringstream convert;  // stream used for the conversion
	convert << telapsed;      // converts the telapsed(long int) to string class
	timeval = convert.str();
	
	if(1){//Code to display the the time elapsed at the proper position
			Position Center = foosballWindow.GetCenter();
	
			// Create bounding box for text
			Position UpperLeft = Center + Position(5.0,0.2);
			Position LowerRight = Center + Position(9.0,0.8);

			// Display the text
			foosballWindow.RenderText(UpperLeft, LowerRight, timeval, Red);
		}
	
	return 1;

}

/*Functions W4MouseClick1,W1MouseClick1,W0MouseClick1 Created by LabBatch 32 and modified by us suitably(with permission)
These functions are the callback functions for the windows W0,W1,W4 i.e. FOOSBALL,Main Menu,Instructions.
*/

int W1MouseClick1(const Position &px);// Function prototype

//Function to read the mouse click from the INSTRUCTIONS window:-
int W4MouseClick1(const Position &p4) {
	if (Back.IsInside(p4)) {//If Back button was clicked from the Instructions window
	        // Close window W4 and open W3
        	W4.Close();
        	W1.Open();
        	assert(W1.GetStatus() == WindowOpen);
        	
        	//Preparing the window W3
		// Load the bitmaps as,Play,Instructions, Exit and Sets the positions and draws them.
		as.Load("as.xpm");
		assert(as.GetStatus() == BitMapOkay);
		as.SetPosition(Position(0.1, 0.1));
		as.Draw();
		
        	Play.Load("Play.xpm");
		assert(Play.GetStatus() == BitMapOkay);
		Play.SetPosition(Position(1.0, 1.0));
		Play.Draw();
		
        	Instructions.Load("Instructions.xpm");
		assert(Instructions.GetStatus() == BitMapOkay);
		Instructions.SetPosition(Position(1.0, 2.0));
		Instructions.Draw();
	
        	Exit.Load("Exit.xpm");
		assert(Exit.GetStatus() == BitMapOkay);
		Exit.SetPosition(Position(1.0, 3.0));
		Exit.Draw();

		W1.SetMouseClickCallback(W1MouseClick1);
		
		

		}	
	}



//Function to read the mouse click from the MAIN MENU window:-
int W1MouseClick1(const Position &px) {
	if (Play.IsInside(px)) {// If Play is clicked
        	// Close  window W1 and open W2
        	W1.Close();
        	foosballWindow.Open();
  		assert(foosballWindow.GetStatus() == WindowOpen);
		int g;
		srand(time(NULL));// Sets seed value for randomisation of ball x coordinate
 		//float posx=0.5,posy=0.03;//postion incrementers are initialised
		//Position p(2.0,10.0);//sets the initial position of ball
		// Load the bitmaps Left, Right, Stop for playing the game
		Left.Load("Left.xpm");
		assert(Left.GetStatus() == BitMapOkay);
		Left.SetPosition(Position(15.3,12.0 ));
		Left.Draw();
	
		Right.Load("Right.xpm");
		assert(Right.GetStatus() == BitMapOkay);
		Right.SetPosition(Position(17.4,12.0 ));
		Right.Draw();
		
		Stop.Load("stop.xpm");
		assert(Stop.GetStatus() == BitMapOkay);
		Stop.SetPosition(Position(16.4,12.0 ));
		Stop.Draw();
		// store tstart value to be used in calculating telapsed
		tstart=GetMilliseconds();
		/*Setting the callbacks for the foosballWindow.
		MClick to play the game
		Loop to check conditions of collision and AI code  
		*/
		foosballWindow.SetMouseClickCallback(MClick);
		foosballWindow.SetTimerCallback(Loop);


		//scoreboard with border
		foosballWindow.RenderRectangle(Position(15.0,4.0), Position(19.0,6.0),White, true);
 		//timer with border
 		foosballWindow.RenderRectangle(Position(15.0,10.0), Position(19.0,12.0),White, true);

		// Get Center of Window
		Position Center = foosballWindow.GetCenter();
		if(1){
			// Create bounding box for text
			Position UpperLeft = Center + Position(5.0,-8.0);
			Position LowerRight = Center + Position(9.0,-6.0);

			// Display the text
			foosballWindow.RenderText(UpperLeft, LowerRight, "SCORE", Red);
		}
		// Get Center of Window
		if(1){
			Position Center = foosballWindow.GetCenter();
			// Create bounding box for text
			Position UpperLeft = Center + Position(5.0,-7.0);
			Position LowerRight = Center + Position(9.0,-5.0);

			// Display the text
			foosballWindow.RenderText(UpperLeft, LowerRight,"COMP VS HUMAN", Red);
		}
		// Get Center of Window
		if(1){
			Position Center = foosballWindow.GetCenter();
	
			// Create bounding box for text
			Position UpperLeft = Center + Position(5.0,-0.7);
			Position LowerRight = Center + Position(9.0,0.0);

			// Display the text
			foosballWindow.RenderText(UpperLeft, LowerRight, "TIMER", Red);
		}
    		 /*the lines below are used to print the score as 0 for both the teams*/

		ostringstream convert;   // stream used for the conversion
		convert << goalR;      
		scoreA = convert.str(); 
		if(1){
			Position Center = foosballWindow.GetCenter();
			// Create bounding box for text
			Position UpperLeft = Center + Position(6.0,-5.5);
			Position LowerRight = Center + Position(10.0,-3.5);
			// Display the text
			foosballWindow.RenderText(UpperLeft, LowerRight,scoreA, Red);
		}
		convert << goalB;      
		scoreB = convert.str();
		if(1){
			Position Center = foosballWindow.GetCenter();
			// Create bounding box for text
			Position UpperLeft = Center + Position(4.0,-5.5);
			Position LowerRight = Center + Position(8.0,-3.5);
			// Display the text
			foosballWindow.RenderText(UpperLeft, LowerRight,scoreB, Red);
		}
			

		foosballWindow.StartTimer(5);// Starts the timer tick callback execution

        }

	
	
	else if (Instructions.IsInside(px)) {//If Instructions button was clicked 
        	// Close  window W1 and open W4
        	W1.Close();
        	W4.Open();
        	
        	assert(W4.GetStatus() == WindowOpen); 
 	
        	//Prepring the contents of INSTRUCTIONS window:-
		// Load the bitmaps Background,Info, Abt,Back
		// Info and Abt contain the instructions and credits
        	Background.Load("as.xpm");
        	assert(Background.GetStatus() == BitMapOkay);
        	Background.SetPosition(Position(0, 0));          // Display the background bitmap image at the starting position    
        	Background.Draw();
        	
        	Info.Load("Info.xpm");
        	assert(Info.GetStatus() == BitMapOkay);
        	Info.SetPosition(Position(1.0, 5.0));              
        	Info.Draw();

		Abt.Load("Abt.xpm");
        	assert(Abt.GetStatus() == BitMapOkay);
        	Abt.SetPosition(Position(14.0, 1.0));              
        	Abt.Draw();
        	        	       
        	Back.Load("Back.xpm");
        	assert(Back.GetStatus() == BitMapOkay);
        	Back.SetPosition(Position(1.0, 12.0));              
        	Back.Draw();
	
     		W4.SetMouseClickCallback(W4MouseClick1);  //Reading the mouse click from the INSTRUCTIONS window
        }


	
	else if (Exit.IsInside(px)) {
        	// Close  window W1 
        	W1.Close();
        }

}

 

        
int W0MouseClick1(const Position &p1) {
	
       	// Close  window W0 and open W1
       	W0.Close();
       	W1.Open();
       	assert(W1.GetStatus() == WindowOpen);
	// Load the bitmaps as:background,Play,Instructions and Exit
	as.Load("as.xpm");
	assert(as.GetStatus() == BitMapOkay);
	as.SetPosition(Position(0.1, 0.1));
	as.Draw();
	
       	Play.Load("Play.xpm");
	assert(Play.GetStatus() == BitMapOkay);
	Play.SetPosition(Position(1.0, 1.0));
	Play.Draw();

       	Instructions.Load("Instructions.xpm");
	assert(Instructions.GetStatus() == BitMapOkay);
	Instructions.SetPosition(Position(1.0, 2.0));
	Instructions.Draw();
	
	Exit.Load("Exit.xpm");
	assert(Exit.GetStatus() == BitMapOkay);
	Exit.SetPosition(Position(1.0, 3.0));
	Exit.Draw();

        // Register the call backs for each window
	W1.SetMouseClickCallback(W1MouseClick1);

	
}

int ApiMain() {

	W0.Open();
        assert(W0.GetStatus() == WindowOpen);
       	//Setting the background image for the W0 window
        aaa.Load("Background.xpm");
        assert(aaa.GetStatus() == BitMapOkay);
        aaa.SetPosition(Position(0.1,0.1));
        aaa.Draw();
        // Sets the mouse callback for the W0 window,click anywhere to go to the main window.
        W0.SetMouseClickCallback(W0MouseClick1);
	
        
        return 0;
}

