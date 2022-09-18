#include <fstream>
#include <iostream>

using namespace std;
int main(){
    int max_iteration = 80;
    float r_start = -0.7,r_end = 0;
    float i_start = -1.8,i_end =-1.2;
    // float r_start = -2,r_end = 2;
    // float i_start = -2,i_end =-1.2;
    int size = 500 ;
    // int width =  size*(r_end-r_start)/(i_end-i_start);
    // int height =  size*(i_end-i_start)/(r_end-r_start);
    int width =  583;
    int height =  428;
    cout << width << endl;
    cout << height << endl;

    float steps_x = (r_end-r_start)/width;
    float steps_y = (i_end-i_start)/height;

    ofstream img ("picture.ppm");
    img << "P3" << endl;
    img << width << " " << height << endl;
    img << 120 << endl;
    int row = 0 ;
    for(float i = i_start; i < i_end;i= i + steps_y){
        row = 0 ;
        for(float r = r_start; r < r_end;r=r+steps_x){
            row ++ ;
            double x = 0;
            double y = 0;
            bool didBreal = false;
            double xo = i;
            double yo = r;
            int iteration = 0;
            while (x*x + y*y <= 2*2 && iteration < max_iteration){
                    float xtemp = x*x - y*y + xo;
                     y = 2*x*y + yo;
                     x = xtemp;
                    iteration++;
            }
            img << iteration*(255/max_iteration) << " " << iteration*(255/max_iteration) << " " << iteration*(255/max_iteration) << endl;
        }
        cout << row << endl;
    }

    system("open picture.ppm");
    return 0;
}
