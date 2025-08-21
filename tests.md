# Comprehensive Bad Format Edge Cases for Cub3D Testing

## 1. Invalid File Extensions

### test_bad_ext.txt
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\n.cub file required"

## 2. Missing Elements

### test_missing_north.cub
```
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nMissing north texture"

### test_missing_floor.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nMissing floor color"

### test_missing_all_textures.cub
```
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nMissing north texture"

## 3. Duplicate Elements

### test_duplicate_north.cub
```
NO textures/north.xpm
NO textures/north2.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nDuplicate texture/color"

### test_duplicate_floor.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
F 255,255,255
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nDuplicate texture/color"

## 4. Invalid Identifiers

### test_malformed_id1.cub
```
N E textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid texture/color syntax"

### test_malformed_id2.cub
```
N O textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid texture/color syntax"

### test_invalid_id.cub
```
XX textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid texture/color syntax"

### test_random_letters.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
Z 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid texture/color syntax"

## 5. Invalid File Extensions/Paths

### test_wrong_extension.cub
```
NO textures/north.png
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nTexture must be .xpm file"

### test_nonexistent_file.cub
```
NO textures/nonexistent.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nCannot open texture file"

### test_no_extension.cub
```
NO textures/north
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nTexture must be .xpm file"

## 6. Invalid Color Formats

### test_color_out_of_range.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 256,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid color format"

### test_negative_color.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F -1,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid color format"

### test_incomplete_color.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid color format"

### test_non_numeric_color.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F abc,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid color format"

### test_extra_color_values.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0,50
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid color format"

### test_leading_zeros.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 001,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid color format"

## 7. Extra Content After Valid Elements

### test_extra_content.cub
```
NO textures/north.xpm extra_stuff
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid texture/color format"

### test_extra_after_color.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0 extra
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid color format"

## 8. Missing Data After Identifier

### test_no_path.cub
```
NO
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid texture/color format"

### test_only_spaces.cub
```
NO    
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid texture/color format"

## 9. Wrong Number of Elements

### test_too_few_elements.cub
```
NO textures/north.xpm
SO textures/south.xpm
F 220,100,0

111111
100001
111111
```
**Expected**: "Error\nWrong .cub file syntax"

### test_empty_file.cub
```
```
**Expected**: "Error\nWrong .cub file syntax"

## 10. Map Issues

### test_no_map.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0
```
**Expected**: "Error\nNo map found"

### test_empty_map.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0


```
**Expected**: "Error\nNo map found"

### test_invalid_map_char.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
10X001
111111
```
**Expected**: "Error\nInvalid character in map"

### test_no_player.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nNo starting player position"

### test_multiple_players.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
1N0S01
111111
```
**Expected**: "Error\nMultiple player positions"

### test_empty_line_in_map.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001

111111
```
**Expected**: "Error\nEmpty line in map"

### test_map_not_enclosed.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

011111
100001
111111
```
**Expected**: "Error\nMap not surrounded by walls"

### test_hole_in_map.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
10 001
100001
111111
```
**Expected**: "Error\nMap not surrounded by walls" or "Error\nUnreachable area(s) in map"

## 11. File System Issues

### test_empty_filename.cub
(Test with empty string as filename)
**Expected**: "Error\n.cub file required" or "Error\nCannot open file"

### test_directory_as_file.cub
(Test with directory name instead of file)
**Expected**: "Error\nCannot open file"

## 12. Mixed Valid/Invalid

### test_mixed_single_double.cub
```
N S textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nInvalid texture/color syntax"

### test_tabs_and_spaces.cub
```
NO	textures/north.xpm
SO  textures/south.xpm
WE		textures/west.xpm
EA textures/east.xmp
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nTexture must be .xpm file"

## 13. Boundary Cases

### test_255_boundary.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 255,255,255
C 0,0,0

111111
100001
111111
```
**Expected**: Should work (valid boundary values)

### test_256_boundary.cub
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xmp
F 255,255,256
C 0,0,0

111111
100001
111111
```
**Expected**: "Error\nInvalid color format"

### test_very_long_path.cub
```
NO textures/very/very/very/very/very/very/very/very/very/very/very/very/very/very/very/very/very/very/very/very/long/path/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nCannot open texture file" (if path doesn't exist)

## 14. Unicode/Special Characters

### test_special_chars.cub
```
NO textures/nörth.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
111111
```
**Expected**: "Error\nCannot open texture file" (likely)

## Quick Test Commands:


These edge cases cover every possible way the parsing can fail and should thoroughly test your error handling!