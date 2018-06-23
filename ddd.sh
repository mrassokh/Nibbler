if brew ls --versions sfml > /dev/null; then
    echo "sfml installed";
else
    brew install SFML;
fi
