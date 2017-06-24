#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

extern "C" {
#include "extApi.h"
}

int main(int argc, char *argv[])
{
  simxInt client_id = simxStart("127.0.0.1", 3000, true, true, 1000, 10);
  if(client_id == -1) {
    cerr << "ERROR : Cannot connect to simulation" << endl;
    return -1;
  }

  simxInt left_motor_handle = -1;
  simxInt right_motor_handle = -1;

  simxInt left_encoder_handle = -1;
  simxInt right_encoder_handle = -1;

  {
    simxInt jcount = 0;
    simxInt* jhandles = NULL;
    simxGetObjects(client_id, sim_object_joint_type, &jcount, &jhandles, simx_opmode_oneshot_wait);

    simxInt ncount = 0;
    simxChar* names = NULL;
    simxGetObjectGroupData(client_id, sim_object_joint_type, 0, &jcount, &jhandles, NULL, NULL, NULL, NULL, &ncount, &names, simx_opmode_oneshot_wait);

    {
      char* cur = names;
      for(int i = 0 ; i < ncount ; i++) {
        if(strcmp("left_motor_joint", cur) == 0) {
          left_motor_handle = jhandles[i];
        }
        if(strcmp("right_motor_joint", cur) == 0) {
          right_motor_handle = jhandles[i];
        }
        if(strcmp("left_encoder_joint", cur) == 0) {
          left_encoder_handle = jhandles[i];
        }
        if(strcmp("right_encoder_joint", cur) == 0) {
          right_encoder_handle = jhandles[i];
        }
        //cout << jhandles[i] << " : " << cur << endl;
        cur += strlen(cur)+1;
      }
    }
  }

  if(left_motor_handle == -1 || right_motor_handle == -1) {
    cerr << "ERROR : Could not find motors" << endl;
    return -1;
  }

  if(left_encoder_handle == -1 || right_encoder_handle == -1) {
    cerr << "ERROR : Could not find motors" << endl;
    return -1;
  }

  {
    simxFloat v = 0;
    cout << "Enter motors speed : " << endl;
    cin >> v;
    simxSetJointTargetVelocity(client_id, left_motor_handle, v*0.01745322, simx_opmode_oneshot_wait);
    simxSetJointTargetVelocity(client_id, right_motor_handle, -v*0.01745322, simx_opmode_oneshot_wait);
  }

  for(int i = 0 ; i < 10 ; i++) {
    simxFloat lp = 0;
    simxFloat rp = 0;
    simxGetJointPosition(client_id, left_encoder_handle, &lp, simx_opmode_oneshot_wait);
    simxGetJointPosition(client_id, right_encoder_handle, &rp, simx_opmode_oneshot_wait);
    cout << left << std::setw(10) << lp << " ; " << std::setw(10) << rp << endl;
  }

  simxFinish(client_id);
  return 0;
}
