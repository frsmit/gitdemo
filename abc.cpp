#include <iostream>
#include <vector>

using namespace std;

struct Color {
    int r, g, b;
};

int brightness(const Color& color) {
    return (color.r * 299 + color.g * 587 + color.b * 114) / 1000;
}

string classify_color(const Color& color) {
    int threshold = 128; // Adjust this threshold as needed
    return (brightness(color) < threshold) ? "Dark" : "Light";
}

int main() {
    int num_colors;

    cout << "Enter the number of colors: ";
    cin >> num_colors;

    vector<Color> colors(num_colors);
    vector<Color> light_colors;
    vector<Color> dark_colors;

    cout << "Enter the RGB values for each color:\n";
    for (int i = 0; i < num_colors; ++i) {
        cout << "Color " << i + 1 << ": ";
        cin >> colors[i].r >> colors[i].g >> colors[i].b;

        if (classify_color(colors[i]) == "Light") {
            light_colors.push_back(colors[i]);
        } else {
            dark_colors.push_back(colors[i]);
        }
    }

    cout << "\nLight Colors:\n";
    for (const Color& color : light_colors) {
        cout << "RGB: (" << color.r << ", " << color.g << ", " << color.b << ")" << endl;
    }

    cout << "\nDark Colors:\n";
    for (const Color& color : dark_colors) {
        cout << "RGB: (" << color.r << ", " << color.g << ", " << color.b << ")" << endl;
    }

    return 0;
}