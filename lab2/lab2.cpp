#include <iostream>
#include <sys/sysinfo.h>

using namespace std;

const double kilobyte = 1024;
const double megabyte = 1024 * 1024;
const double gigabyte = 1024 * 1024 * 1024;

int main() {
  struct sysinfo systeminfo;
  sysinfo(&systeminfo);

  //all sizes in bytes

  cout << "SYSTEM INFO:";
  
  cout << "\n\tRAM.\n";
  
  cout << "\t\tTotal: " << systeminfo.totalram << "\n";
  cout << "\t\tTotal(KB): " << (double)systeminfo.totalram/kilobyte << "\n";
  cout << "\t\tTotal(MB): " << (double)systeminfo.totalram/megabyte << "\n";
  cout << "\t\tTotal(GB): " << (double)systeminfo.totalram/gigabyte << "\n";
  
  cout << "\n\t\tFree: " << systeminfo.freeram << "\n";
  cout << "\t\tFree(KB): " << (double)systeminfo.freeram/kilobyte << "\n";
  cout << "\t\tFree(MB): " << (double)systeminfo.freeram/megabyte << "\n";
  cout << "\t\tFree(GB): " << (double)systeminfo.freeram/gigabyte << "\n";
    
  cout << "\n\t\tShared: " << systeminfo.sharedram << "\n";
  cout << "\t\tShared(KB): " << (double)systeminfo.sharedram/kilobyte << "\n";
  cout << "\t\tShared(MB): " << (double)systeminfo.sharedram/megabyte << "\n";
  cout << "\t\tShared(GB): " << (double)systeminfo.sharedram/gigabyte << "\n";
  
  cout << "\n\t\tBuffer: " << systeminfo.bufferram << "\n";
  cout << "\t\tBuffer(KB): " << (double)systeminfo.bufferram/kilobyte << "\n";
  cout << "\t\tBuffer(MB): " << (double)systeminfo.bufferram/megabyte << "\n";
  cout << "\t\tBuffer(GB): " << (double)systeminfo.bufferram/gigabyte << "\n";
  
  cout << "\n\tSwap.";
  
  cout << "\n\t\tTotal: " << systeminfo.totalswap << "\n";
  cout << "\t\tTotal(KB): " << (double)systeminfo.totalswap/kilobyte << "\n";
  cout << "\t\tTotal(MB): " << (double)systeminfo.totalswap/megabyte << "\n";
  cout << "\t\tTotal(GB): " << (double)systeminfo.totalswap/gigabyte << "\n";
  
  cout << "\n\t\tFree: " << systeminfo.freeswap << "\n";
  cout << "\t\tFree(KB): " << (double)systeminfo.freeswap/kilobyte << "\n";
  cout << "\t\tFree(MB): " << (double)systeminfo.freeswap/megabyte << "\n";
  cout << "\t\tFree(GB): " << (double)systeminfo.freeswap/gigabyte << "\n";

  cout << "\nmem_unit: " << systeminfo.mem_unit << "\n";
  //mem_unit * size = size in bytes (def 1)
}
