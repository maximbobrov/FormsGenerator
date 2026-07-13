# Forms Generator

Forms Generator is a Qt desktop application for preparing, editing, previewing, and printing form records backed by a SQL database.

The application provides two main workflows:

- editing reference tables for form types, answers, areas, and locations;
- generating printable forms with QR codes and PDF preview support.

## Main Features

- Qt Widgets user interface with a left navigation panel.
- SQL table editing through Qt SQL models.
- Form generation and print/preview workflow.
- QR code generation with AES-based payload encoding.
- English/Russian UI language selection.
- Qt resource-based styling and icons.

## Project Layout

- `FormsGenerator.pro` - qmake project file.
- `main.cpp` - application entry point and style loading.
- `mainwindow.*` - main application shell and navigation.
- `pages.*` - form parameter, language, table, and preview pages.
- `edittablespage.cpp` - SQL table editing workflow.
- `generateformspage.cpp` - form generation and print/preview workflow.
- `commondata.*` - shared UI state, database access, QR/PDF helpers, and form data.
- `navbutton.*` - custom navigation button widget.
- `QRCodeGenerator.*` and `aes256.*` - bundled QR and encryption helpers.
- `images/` and `qss/` - UI assets and stylesheet resources.

## Build

The project is configured for Qt 5 with qmake.

Required Qt modules:

- Core
- GUI
- Widgets
- SQL
- Print Support

External library:

- `poppler-qt5`

Typical build flow:

```bash
qmake FormsGenerator.pro
make
```

On Windows, use the matching Qt toolchain and make tool for the installed Qt kit.
