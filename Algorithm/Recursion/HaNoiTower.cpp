#include <iostream>
#include <vector>
#include <iomanip>

// Global state to represent the rods
std::vector<std::vector<int> > rods(3);

// Function prototypes
void hanoi_tower_visualize(int n, char source, char auxiliary, char destination);
void move_disk_visualize(int n, char from_rod, char to_rod);
void print_rods(int total_disks);
int get_rod_index(char rod);

/**
 * @brief Prints the action of moving a single disk and updates the visual state.
 */
void move_disk_visualize(int n, char from_rod, char to_rod) {
    int from_index = get_rod_index(from_rod);
    int to_index = get_rod_index(to_rod);

    // Find the disk in the source rod
    int disk_to_move = rods[from_index].back();
    rods[from_index].pop_back();

    // Move the disk to the destination rod
    rods[to_index].push_back(disk_to_move);
}

/**
 * @brief Solves the Tower of Hanoi puzzle with a visual output.
 */
void hanoi_tower_visualize(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        move_disk_visualize(1, source, destination);
        std::cout << "\n-----------------------------------" << std::endl;
        print_rods(rods[0].size() + rods[1].size() + rods[2].size());
        return;
    }
    
    hanoi_tower_visualize(n - 1, source, destination, auxiliary);
    move_disk_visualize(n, source, destination);
    std::cout << "\n-----------------------------------" << std::endl;
    print_rods(rods[0].size() + rods[1].size() + rods[2].size());
    hanoi_tower_visualize(n - 1, auxiliary, source, destination);
}

/**
 * @brief Maps a character rod name to its vector index.
 */
int get_rod_index(char rod) {
    if (rod == 'A') return 0;
    if (rod == 'B') return 1;
    return 2; // rod 'C'
}

/**
 * @brief Prints the current state of all three rods visually.
 */
void print_rods(int total_disks) {
    std::cout << "Current State of the Rods:" << std::endl;
    std::cout << "   A   " << "   B   " << "   C   " << std::endl;
    std::cout << "  ---  " << "  ---  " << "  ---  " << std::endl;

    for (int i = total_disks - 1; i >= 0; --i) {
        // Print rod A
        if (i < rods[0].size()) {
            std::cout << std::setw(3) << rods[0][i] << "    ";
        } else {
            std::cout << "      ";
        }

        // Print rod B
        if (i < rods[1].size()) {
            std::cout << std::setw(3) << rods[1][i] << "    ";
        } else {
            std::cout << "      ";
        }

        // Print rod C
        if (i < rods[2].size()) {
            std::cout << std::setw(3) << rods[2][i] << "    ";
        } else {
            std::cout << "      ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int num_disks;
    char source_rod = 'A';
    char auxiliary_rod = 'B';
    char destination_rod = 'C';
    
    std::cout << "Enter the number of disks on rod " << source_rod << ": ";
    std::cin >> num_disks;
    
    if (num_disks <= 0) {
        std::cout << "Invalid number of disks. Please enter a positive integer." << std::endl;
        return 1;
    }

    // Initialize rod A with disks
    for (int i = num_disks; i >= 1; --i) {
        rods[0].push_back(i);
    }

    std::cout << "\nInitial State:" << std::endl;
    print_rods(num_disks);
    
    std::cout << "\nStarting the Tower of Hanoi simulation..." << std::endl;
    hanoi_tower_visualize(num_disks, source_rod, auxiliary_rod, destination_rod);
    std::cout << "\nAll disks have been moved!" << std::endl;
    
    return 0;
}
