cmd_63c7e176936bd0ce27867409794f8ec43bf0859f.intermediate := LD_LIBRARY_PATH=/home/pi/kompilacija/node-v14.15.4/out/Release/lib.host:/home/pi/kompilacija/node-v14.15.4/out/Release/lib.target:$$LD_LIBRARY_PATH; export LD_LIBRARY_PATH; cd ../.; mkdir -p /home/pi/kompilacija/node-v14.15.4/out/Release/obj/gen/src/node/inspector/protocol; python tools/inspector_protocol/code_generator.py --jinja_dir tools/inspector_protocol --output_base "/home/pi/kompilacija/node-v14.15.4/out/Release/obj/gen/src/" --config src/inspector/node_protocol_config.json