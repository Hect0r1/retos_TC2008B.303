clickNum = 0;

function setup() {
  createCanvas(405, 400)
}

function draw() {
  if(clickNum == 0){
    background(220);
  }
  if(clickNum == 1){
    background(220);
    noFill();
    stroke(0, 0, 0);
    bezier(204,342, 184,72, 121, 64, 18,63);
    stroke(255, 102, 0);
    stroke(0, 0, 0);
   bezier(390,63,287,64,224,72,204,342);
  }
  if(clickNum == 2){
    yDeformation = 20;
    xDeformation = 20;
    fill(220);
    steps = 10;
    for (i = 0; i <= steps; i++) {
      if(i == steps){
        yDeformation = 20;
        xDeformation = 40
      }
      t = i / float(steps);
      x = bezierPoint(18, 121, 184, 204, t);
      y = bezierPoint(63, 64, 72, 342, t); 
      fill(0,0,255);
      ellipse(x,y,xDeformation, yDeformation);
      yDeformation+= 3;
    }
    yDeformation = 20;
    xDeformation = 40;
    for (i = 0; i <= steps; i++) {
      if(i == 1){
        xDeformation = 20;
        yDeformation = 47
      }
      t = i / float(steps);
      x = bezierPoint(204, 224, 287, 390, t);
      y = bezierPoint(342, 72, 64 ,63, t);
      fill(0,0,255);
      ellipse(x, y, xDeformation, yDeformation);
      yDeformation -= 3;
    }
    clickNum = 3
  }
  if(clickNum == 4){
    clickNum = 5;
    animation(18, 63, 121, 64, 184, 72, 204, 342);
  }
}

async function animation(x1, y1, x2, y2, x3, y3, x4, y4){
  fill(220);
  steps = 60;
  for(i = 0; i <= steps; i++){
    await sleep(60);
    if(i == steps){
        yDeformation = 20;
        xDeformation = 40
    }
    t = i / float(steps);
    background(220);
    x = bezierPoint(x1, x2, x3, x4, t);
    y = bezierPoint(y1, y2, y3, y4, t);
    fill(0,0,255);
    ellipse(x, y, xDeformation, yDeformation);
    yDeformation+= 0.5
  }
  if(clickNum == 5){
    clickNum = 6;
    animationPt2(204, 342, 224, 72, 287, 64, 390, 63);
  }
}

async function animationPt2(x1, y1, x2, y2, x3, y3, x4, y4){
  fill(220);
  steps = 60;
  for(i = 0; i <= steps; i++){
    await sleep(60);
    if(i == 1){
      xDeformation = 20;
      yDeformation = 47;
    }
    else if(i == steps){
      yDeformation = 20
    }
    t = i / float(steps);
    background(220);
    x = bezierPoint(x1, x2, x3, x4, t);
    y = bezierPoint(y1, y2, y3, y4, t);
    fill(0,0,255);
    ellipse(x, y, xDeformation, yDeformation);
    yDeformation -= 0.5
  }
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

function mouseClicked(){
  clickNum++;
}
