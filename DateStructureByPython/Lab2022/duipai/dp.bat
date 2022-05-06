g++ -Wall -std=c++20 std.cpp -o std
g++ -Wall -std=c++20 bl.cpp -o bl
g++ -Wall -std=c++20 mkd.cpp -o mkd

:loop
    mkd.exe > 1.txt
    std.exe < 1.txt > 2.txt
    bl.exe < 1.txt > 3.txt
    fc 2.txt 3.txt

if not errorlevel 1 goto loop
pause
goto loop