cmd_a84d5e6f141e74e89a62537eee6f34d8b2ada316.intermediate := LD_LIBRARY_PATH=/home/pi/kompilacija/node-v14.15.4/out/Release/lib.host:/home/pi/kompilacija/node-v14.15.4/out/Release/lib.target:$$LD_LIBRARY_PATH; export LD_LIBRARY_PATH; cd ../tools/v8_gypfiles; mkdir -p /home/pi/kompilacija/node-v14.15.4/out/Release/obj.target/v8_snapshot/geni; "/home/pi/kompilacija/node-v14.15.4/out/Release/mksnapshot" --turbo_instruction_scheduling "--target_os=linux" "--target_arch=arm" --startup_src "/home/pi/kompilacija/node-v14.15.4/out/Release/obj.target/v8_snapshot/geni/snapshot.cc" --embedded_variant Default --embedded_src "/home/pi/kompilacija/node-v14.15.4/out/Release/obj.target/v8_snapshot/geni/embedded.S" --no-native-code-counters
