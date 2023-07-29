#include <stdio.h>
#include <math.h>

#define trainingSize sizeof(x_train)/sizeof(x_train[0])
#define e 2.7182

int epochs = 10;
float learning_rate = 0.01;
float loss = 0;

int x_train[6][2] = {
  {2,4},
  {5,1},
  {7,2},
  {2,7},
  {1,9},
  {9,0}
};

int y_train[6] = {
  1,
  0,
  0,
  1,
  1,
  0
};

float weight[2] = {
  0.1,
  0.2
};

float bias = 1.0;

float sigmoid(int x){
  return 1 / ( 1 + pow(e, -x));
}

float getWeightedSums(int *x){
  float total = 0;
  for(int i=0;i<2;i++){
    total += x[i] * weight[i];
  }

  return total + bias;
}

void feedForward(int x[][2], int *y){
  for(int i = 0;i<epochs;i++){
    loss = 0;
    for(int j = 0;j<trainingSize;j++){
      float pred = sigmoid(getWeightedSums(x[j]));
      float error = y[j] - pred;
      loss = error * error; 
      for(int k=0; k<2;k++){
        weight[k] = weight[k] + learning_rate * error * x[j][k];
      }

      bias = bias + learning_rate * error;
    }
    printf("%f\n", loss / trainingSize);
  }
}

float predict(int *x){
  float total = 0;
  for(int i=0;i<2;i++){
    total += x[i] * weight[i];
  }

  return sigmoid(total + bias);
}

int main(){
  feedForward(x_train, y_train);
  int input[2] = {3, 7}; 
  int output = (int)round(predict(input));
  printf("output = %f", predict(input));
  (output == 1)? printf("Student passed") : printf("student failed");
  return 0;
}
























