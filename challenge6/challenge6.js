function setup() {
  createCanvas(400, 400);
}

value = 0;
x1 = 0;
y1 = 0;
x2 = 0;
y2 = 0;
finished = 0;
finished_circle = 0;
x3 = 0;
y3 = 0;
x4 = 0;
y4 = 0;

curveFinished = 0;
updateCurvePoints = 0;
dragPointsCurve = 0;


function draw() {
  if(finished == 0){
    background(255);
  }
  fill(value);
  if(x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0 && finished == 0){
    line(x1,y1,x2,y2);
  }
}
function mousePressed(){
  if(finished == 0){
    x1 = mouseX;
    y1 = mouseY;
  }
  if (finished_circle < 3){
    if(finished_circle == 1){
      x3 = mouseX;
      y3 = mouseY;
    }
    else if(finished_circle == 2){
      x4 = mouseX;
      y4 = mouseY;
    }
    ellipse(mouseX,mouseY, 30, 30);
    finished_circle = finished_circle + 1;
  }
   if(curveFinished == 1){
     let lowestX = x3 - 20;
     let highestX = x3 + 20;
     
     let lowestY = y3 - 20;
     let highestY= y3 + 20;
     
     let lowestX2 = x4 - 20;
     let highestX2 = x4 + 20;
     
     let lowestY2 = y4 - 20;
     let highestY2 = y4 + 20; 
     
     if(mouseX <= x3 && mouseX >= lowestX && mouseX <= highestX && mouseY <= y3 && mouseY >= lowestY && mouseY <= highestY){
       dragPointsCurve = 1;
     }
     if(mouseX <= x4 && mouseX >= lowestX2 && mouseX <= highestX2 && mouseY <= y4 && mouseY >= lowestY2 && mouseY <= highestY2){
       dragPointsCurve = 2;
     }
   }
}

function mouseDragged() 
{
  if(finished == 0){
    x2 = mouseX;
    y2 = mouseY;
  }
  if(dragPointsCurve == 1){
    background(255);
    x3 = mouseX;
    y3 = mouseY;
    ellipse(x3,y3, 30, 30);
    ellipse(x4,y4, 30, 30);
    noFill();
    bezier(x1, y1, x2, y2, x3, y3, x4, y4);
  }
  if(dragPointsCurve == 2){
    background(255);
    x4 = mouseX;
    y4 = mouseY;
    ellipse(x3,y3, 30, 30);
    ellipse(x4,y4, 30, 30);
    noFill();
    bezier(x1, y1, x2, y2, x3, y3, x4, y4);
  }
}

function mouseReleased(){
  if(finished_circle == 3){
    background(255);
    ellipse(x3,y3, 30, 30);
    ellipse(x4,y4, 30, 30);
    noFill();
    bezier(x1, y1, x2, y2, x3, y3, x4, y4);
    finished_circle++;
    curveFinished = 1;
  }
  if(dragPointsCurve == 1 || dragPointsCurve == 2){
    dragPointsCurve = 0;
  }
  finished = 1;
}
