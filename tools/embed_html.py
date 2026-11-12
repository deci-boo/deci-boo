#!/usr/bin/env python3
"""Embed web/game.html into the ESP32 sketch as game_html.h.

Run after every change to web/game.html:
    python3 tools/embed_html.py
"""
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "web" / "game.html"
DST = ROOT / "firmware" / "esp32" / "deci_boo_bridge" / "game_html.h"
DELIM = "DECIBOO"

html = SRC.read_text(encoding="utf-8")
if f"){DELIM}\"" in html:
    raise SystemExit(f"game.html contains the raw-string delimiter ){DELIM}\"")

DST.write_text(
    "// AUTO-GENERATED from web/game.html by tools/embed_html.py — do not edit by hand.\n"
    "#pragma once\n"
    f"static const char GAME_HTML[] PROGMEM = R\"{DELIM}(\n{html}){DELIM}\";\n",
    encoding="utf-8",
)
print(f"wrote {DST.relative_to(ROOT)} ({len(html.encode('utf-8'))} bytes)")
