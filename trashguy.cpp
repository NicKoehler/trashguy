#include <iostream>
#ifdef _WIN32
    #include <windows.h>

    void sleep(float milliseconds) {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>

    void sleep(float milliseconds) {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif

class TrashGuy {

    public:

        std::string right = "(> ^_^)>";
        std::string left = "<(^_^ <)";
        std::string l_space = " ";
        std::string r_space = " ";
        std::string trash = "🗑";
        std::string user = right;
        std::string user_input;
        std::string letter;
        float speed = 100;

        TrashGuy(std::string ui, float s=1) {
            user_input = ui;
            speed /= s;
        }

        void print() {
            std::cout << trash << l_space << user << r_space << user_input << "\r" << std::flush;
            sleep(speed);
        }

        void goRight() {
            print();
            while (!r_space.empty()) {
                r_space = r_space.substr(1, r_space.size()-1);
                l_space += " ";
                print();
            }
        }

        void goLeft() {
            print();
            while (!l_space.empty()) {
                l_space = l_space.substr(1, l_space.size()-1);
                r_space += " ";
                print();
            }
        }

        void takeLetter() {
            letter = user_input.at(0);
            user = letter + left;
            user_input = user_input.substr(1, user_input.size()-1);
            l_space = l_space.substr(1, l_space.size()-1);
            r_space += " ";
        }

        void trashLetter() {
            user = user.substr(1, user.size()-1);
            r_space += " ";
            print();
            user = right;
            print();
            l_space += " ";
            r_space = r_space.substr(1, r_space.size()-1);
        }

        void play() {
            for (char _ : user_input) {
                goRight();
                takeLetter();
                goLeft();
                trashLetter();
            }
        }
};

int main(int argc, char *argv[]) {
    if (argc == 2) {
        TrashGuy(argv[1]).play();
    } else if (argc == 3) {
        TrashGuy(argv[1], std::stof(argv[2])).play();
    }
}
