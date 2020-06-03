double threshold = 960;
double refractoryPeriod = 300;
double bpm = 0;
double lastTime = 0;
double pulse = 0;
const int arrsize = 3000;
int arr[arrsize] = {0};
double arr2[arrsize] = {0};
int temp[3000] = {0};
double median = 0;
int k = 0;
int j = 0;
void setup() 
{
// put your setup code here, to run once:
Serial.begin(9600);
}

void loop() 
{
pulse = analogRead(A0);
if(pulse > threshold && ((millis() - lastTime) > refractoryPeriod))
{
bpm = 60000.0 / ((millis() - lastTime));
lastTime = millis();
}
for(int i = 0; i < arrsize - 1; i++)
{
  arr[i] = arr[i+1];
}
arr[arrsize - 1] = bpm;

for( int m = 0; m < arrsize + 1; m++)
{
  arr2[m] = arr[m];
}

//sorting the array
for(k=0;k<arrsize;++)
  {   
    for(j=k+1;j<arrsize;j++)
    {
      if(arr2[k]>arr2[j])
      {
        temp  = arr2[k];
        arr2[k]=arr2[j];
        arr2[j]=temp;
      }
    }
  }
median = arr2[arrsize/2];
Serial.print(median);
Serial.print(" , ");
Serial.println(pulse);

delay(20);
}
