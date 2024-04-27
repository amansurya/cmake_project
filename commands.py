import subprocess


user_input = input("Enter a command (build, run, clean): ")

if user_input == "build":
    # Execute build command
    # $COMMAND_TO_EXECUTE_FOR_BUILD$x
    subprocess.run(["cmake", "-S", ".", "-B", "build", "-G", "MinGW Makefiles"])
    subprocess.run(["cmake", "--build", "build", "--target", "cpp_app"])

elif user_input == "run":
    # Execute run command
    # $COMMAND_TO_EXECUTE_FOR_RUN$
    subprocess.run(["build\\cpp_app.exe"])

elif user_input == "clean":
    # Execute clean command
    # $COMMAND_TO_EXECUTE_FOR_CLEAN$
    subprocess.run(["rmdir", "/s", "/q", "build"], shell=True)

else:
    print("Invalid command!")