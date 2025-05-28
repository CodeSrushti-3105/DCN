#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
using namespace std;

// Function to convert CIDR to Subnet Mask
string cidrToSubnetMask(int cidr) 
{
    unsigned int mask = 0xFFFFFFFF << (32 - cidr);
    string subnet = to_string((mask >> 24) & 0xFF) + "." +
                    to_string((mask >> 16) & 0xFF) + "." +
                    to_string((mask >> 8) & 0xFF) + "." +
                    to_string(mask & 0xFF);
    return subnet;
}

// Function to calculate number of hosts per subnet
int hostsPerSubnet(int cidr) 
{
    return pow(2, 32 - cidr) - 2; // minus 2 for network and broadcast addresses
}

int main() 
{
    string ip;
    int cidr;

    cout << "Enter IP address (e.g., 192.168.1.0): ";
    cin >> ip;
    cout << "Enter CIDR (e.g., 24): ";
    cin >> cidr;

    if (cidr < 0 || cidr > 32) 
    {
        cout << "Invalid CIDR notation!" << endl;
        return 1;
    }

    string subnetMask = cidrToSubnetMask(cidr);
    int hosts = hostsPerSubnet(cidr);

    cout << "\n--- Subnetting Info ---\n";
    cout << "IP Address: " << ip << "/" << cidr << endl;
    cout << "Subnet Mask: " << subnetMask << endl;
    cout << "Number of Hosts per Subnet: " << hosts << endl;

    return 0;
}
