# Filter Program

## Overview
A command-line tool to apply filters to BMP images.

## Usage

1. **Compile**:
   ```bash
   make filter
2. **Run**:
   ```bash
   ./filter -g images/sample-image.bmp out.bmp
- `-g`: Apply grayscale.
- `-b`: To blur image.
- `-r`: To reflect image.
- `-e ` To detect edges.
- `images/yard.bmp`: Input BMP file.
- `out.bmp`: Output BMP file.

## Example:
### Before Applying grayscsale:
![image](https://github.com/user-attachments/assets/ee3b931f-8786-4e2b-8bf0-d9a6ce7a75c0)
### After applying grayscale:
![image](https://github.com/user-attachments/assets/96c12bdc-25b0-4704-8b99-859edabfec8c)
### After applying edge detection:
