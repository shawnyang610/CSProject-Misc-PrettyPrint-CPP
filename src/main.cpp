//CS780-37 Proj1.2 Pretty Print
//Shawn Yang

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    if (argc<2){
        cout<<"Please supply input file"<<endl;
        return 1;
    }
    ifstream infile;
    ofstream outfile;
    string filename;
    int valueCol;
    int valueRow;
    int minVal;
    int maxVal;
    int pixel;
    
    //Step0 Opening input file, create ouput file
    filename = argv[1];
    try {
        infile.open(filename);
        filename = filename.substr(0, filename.find_first_of("."))+"_PP.txt";
        outfile.open(filename.c_str());
    }catch (exception* e){
        cout<<"Error opening files"<<endl;
        cout << e<<endl;
        return 1;
    }
    //end of step0
    
    //step1 read the 4 header numbers from input
    infile >> valueRow >> valueCol >> minVal >> maxVal;
    //end of step1

    //step2,3
    outfile<<valueRow<<" "<<valueCol<<" "<<minVal<< " "<<maxVal<<endl;
    for (int r=0; r<valueRow; r++){
        for (int c=0; c<valueCol; c++){
            infile>>pixel;
            if (pixel!=0)
                outfile<<pixel<<" ";
            else
                outfile<<"  ";
        }
        outfile<<endl;
    }
    //end of step2,3
    
    //step4
    infile.close();
    outfile.close();
    return 0;
}
