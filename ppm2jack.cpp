
/*
 *
 * Takes a specified .ppm file and converts it to a text
 * document containing a function specifying a series
 * of drawPixel(x,y) calls to draw the "sprite".
 *
 */
 
 #include <iostream>
 #include <fstream>
 #include <cmath>
 #include <string>
 
 using namespace std;
  
 bool isRGBDark(int r, int g, int b);
 void writeJackHeader(ofstream&, string, int, int);
 void writeDrawPixel(ofstream&, bool, int, int);
 void writeJackFooter(ofstream&);
 
 int main(int argc, char* argv[]){
 
    if(argc != 2){
        cout << "Usage: ppm2jack <filename.ppm>" << endl;
    }
 
    string arg1(argv[1]);
    int lastindex = arg1.find_first_of("."); 
    string filename = arg1.substr(0, lastindex); 
    string outfilename = filename + ".txt";
 
    // Set up the input and output files
    ifstream ppmSource(argv[1]);
    ofstream jackFunction(outfilename.c_str());
    
    string type;
    ppmSource >> type; // Grab the image type
    
    int height, width, maxBit;
    ppmSource.ignore(39, '\n'); // Dump the comment line
    ppmSource.ignore(39, '\n'); // Dump the comment line
    ppmSource >> width >> height >> maxBit; // Grab the image metadata
    
    writeJackHeader(jackFunction, filename, width, height); // Write the function header and bounds checking
    
    // Holders for pixel RGB sets
    int r, g, b;
    // Position trackers
    int x = 0;
    int y = 0;
    // ASCII encoded
    if(type == "P3"){
        cout << "Reading an ASCSII-encoded file." << endl;
        while(ppmSource >> r >> g >> b){
            writeDrawPixel(jackFunction, isRGBDark(r,g,b), x, y);
            x += 1;
            if ( x >= width ) {
                x = 0;
                y++;
            }
        }
    }
    // Raw encoded
    else if(type == "P6"){
        cout << "Other yep!" << endl;
    }
    
    writeJackFooter(jackFunction); // Write the function footer
    
    ppmSource.close();
    jackFunction.close();
    return 0;
 }
 
 bool isRGBDark(int r, int g, int b){
    int sum = r + g + b;
    return (sum == 0);
 }
 
 void writeJackHeader(ofstream& os, string name, int width, int height){
    os << "method void drawSprite" << name << "(int x, int y) {" << endl;
    os << "\tif( ((x+" << width << ")>510) | ((y+" << height << ")>254) ) {" << endl;
    os << "\t\treturn;" << endl;
    os << "\t}" << endl;
 }
 
 void writeJackFooter(ofstream& os){
    os << "\treturn;" << endl;
    os << "}" << endl;
 }
 
 void writeDrawPixel(ofstream& os, bool black, int x, int y){
    os << endl;
    os << "\tdo Screen.setColor(" << (black ? "true" : "false") << ");" << endl;
    os << "\tdo Screen.drawPixel((x+" << x << "), (y+" << y << "));" << endl;
 }
