import os
import sys

pid = os.fork()
if pid==0:
    print("child process is running  with PID :",os.getpid())
    try:
        # os.execv("/usr/bin/ps", ["ps"])
        os.system("ps")
    except:
        print("command not found")
        sys.exit(1)
elif pid>0:
    print("Parent process is waiting for the child to finish with PID:", os.getpid())
    _, exit_status = os.wait()   # exit status is between 0 to 255    os.system("ps")
    print("Child process has exited with status", exit_status)
else :
    print("fork failed.")
    sys.exit(1)