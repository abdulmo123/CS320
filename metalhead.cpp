#include <iostream>
#include <cmath>
#include <vector>

class SixStringGuitar {

private:
    unsigned char numberOfFrets;
    double strings_of_guitar [6];

    public:
        SixStringGuitar():
            strings_of_guitar {82.41, 110, 146.8, 196, 246.9, 329.6} {
            numberOfFrets = 21;
        }

    public:
        bool setFretBoardLength(const unsigned char numFrets) {

            numberOfFrets = numFrets;
            if (numberOfFrets >= 1 && numberOfFrets <= 24) {
                return true;
            }
            else {
                return false;
            }
    }

    public:
        double pitchAt(const unsigned char &stringNumber, const unsigned char &fret) {

            int i;
            double equation;
            for (i = 0; i < 6; ++i) {
                equation = strings_of_guitar[stringNumber - 1] * pow (2.0, fret/12.0);
            }
            return equation;
    }

    public:
        std::pair<unsigned char, unsigned char> getStringAndFret(double pitch) {

            std::vector<double> diff_vector;
            int i; int j; int k; int g; int l; int m; int min_diff;
            double diff;
            int frets [6] = {2, 2, 3, 3, 3, 4};

            for (i = 0; i < 6; i++) {
                diff = (double)(abs(pitch - strings_of_guitar[i]));
                diff = diff * 1.00;
                diff_vector.push_back(diff);
            }

            for (j = 0; j < diff_vector.size(); j++) {
                if (min_diff > diff_vector[j]) {
                    min_diff = diff_vector[j];
                }
            }

            for (k = 0; k < diff_vector.size(); k++) {
                if (min_diff == diff_vector[k]) {
                    g = k;
                }
            }

            for (l = 0; l < 6; l++) {
                if (g == l) {
                    strings_of_guitar[l];
                    break;
                }
            }

            for (m = 0; m < 6; m++) {
                if (g == m) {
                    frets[m];
                    break;
                }
            }

            std::cout << "Index of string: " << l << std::endl << "Index of fret: " << m << std::endl;
            std::cout << "Value of string at given index: " << strings_of_guitar[g] << std::endl << "Value of fret at given index: "<< frets[g];
    }

    public:
        void tuneString(unsigned char string, const double pitch) {

            int i;
            for (i = 0; i < 6; i++) {
                if (i == string - 1) {
                    strings_of_guitar[i] = pitch;
                }
                std::cout << strings_of_guitar[i] << "  ";
            }
            std::cout << std::endl;
    }
};

int main() {

    SixStringGuitar my_guitar;

    std::cout << my_guitar.setFretBoardLength(0) << std::endl;
    std::cout << my_guitar.pitchAt(3, 5) << " Hz" << std::endl;
    my_guitar.getStringAndFret(323);
    std::cout << std::endl;
    my_guitar.tuneString(4,113.7);
}
