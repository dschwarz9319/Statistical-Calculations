#include <iostream>
#include <math.h>



using namespace std;

int main(){

    int array_size = 8;
    int arr[8] = {9,2,5,4,5,7, 9, 9};
    float total = 0;
    float mean = 0;
    int median = 0;
    int modeMax = 0;
    int newModeMax = 0;
    int mode = 0;
    int temp = 0;
    int sigmaXi = 0;
    int medianValue = array_size/2;
    float standardDeviation = 0;


    //initializing elements in the array
    /*
    for (int i=0; i < array_size; i++){
        arr[i] = i;
    }
   */


    //displays sample data to user
    cout << "Data Sample Given:" << endl;
    for (int i=0; i < array_size; i++){
        cout << arr[i] << endl;
    }
    cout << endl << endl;

    //Bubble sort to order array
    for(int i=1;i<array_size; i++) {
        for(int j=0;j<(array_size-i); j++)
            if(arr[j]>arr[j+1]) {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
    }


    //displays sorted sample data to user
    cout << "Sorted Data Sample Given:" << endl;
    for (int i=0; i < array_size; i++){
        cout << arr[i] << endl;
    }
    cout << endl << endl;

    //Counts repeated instances of data to get Mode
     for (int i=0; i < array_size; i++){
        if (arr[i] == arr[i + 1]){
            newModeMax++;
        }
            else {
                newModeMax = 0;
            }
            if (newModeMax > modeMax){
                modeMax = newModeMax;
                mode = arr[i];
            }
        }
    cout << "Mode of Sample is: " << mode << endl;

    //Takes the element in the middle of the sorted array
    //to find the median
    median = arr[medianValue];
    cout << "Median of Sample is " << median << endl;

    //Totals Data to figure out the Mean
    for (int i = 0; i < array_size; i++){
        total = total + arr[i];
    }


//sigma(xi)/n
mean = total/array_size;
total = 0;

    //Prints out mean of sample set
    cout << "Mean of Sample is: " << mean << endl;

    //Sigma x(i) - x(bar)^2
     for (int i = 0; i < array_size; i++){
       total = total + ((arr[i]- mean) * (arr[i] - mean));
       //cout << total << endl;
    }

//Numerator/ n-1
total = total / (array_size - 1);

//Square root of above number
standardDeviation = sqrt(total);

//Prints out Standard Deviation
cout << "Standard Deviation of Sample Set is: " << total << endl << endl;

total = 0;
//Sigma x(i) - x(bar)^3
     for (int i = 0; i < array_size; i++){
       total = total + ((arr[i]- mean) * (arr[i] - mean) * (arr[i] - mean));
       //cout << total << endl;
    }

total = total / ((array_size - 1) * (standardDeviation * standardDeviation * standardDeviation));

//Prints of Coefficient of Skewness
cout << "Coefficient of Skewness is: " << total << endl;

total = 0;
//Sigma x(i) - x(bar)^4
     for (int i = 0; i < array_size; i++){
       total = total + ((arr[i]- mean) * (arr[i] - mean) * (arr[i] - mean) * (arr[i] - mean));
       //cout << total << endl;
    }

total = total / ((array_size - 1) * (standardDeviation * standardDeviation * standardDeviation * standardDeviation));

//Prints of Coefficient of Kurtosis
cout << "Coefficient of Kurtosis is: " << total << endl;


//Prints coefficient of Excess Kurtosis
total = total - 3;
cout << "Coefficient of Excess Kurtosis is: " << total << endl;

return 0;
}
