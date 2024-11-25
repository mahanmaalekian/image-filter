# Filter Program

## Overview
A command-line tool to apply filters to BMP images. Currently, the `grayscale` filter is set up but does not modify the image yet.

## Usage

1. **Compile**:
   ```bash
   make filter
2. **Run**:
   ```bash
   ./filter -g images/yard.bmp out.bmp
- `-g`: Apply grayscale.
- `-b`: To blur image.
- `-r`: To reflect image.
- `-e ` To detect edges.
- `images/yard.bmp`: Input BMP file.
- `out.bmp`: Output BMP file.

  ##Example:
  
