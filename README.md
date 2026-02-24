<h1 align="center">🚀 C-Programming-Practice</h1>

<p align="center">
  <em>A collection of ongoing C projects exploring low-level graphics and logic.</em>
</p>

<hr>

<h2>🧊 Project: Rotating Cube</h2>

<p>This project renders a 3D wireframe cube in a window. It relies on the <strong>SDL2</strong> library for graphics and the standard <strong>Math</strong> library for rotation calculations.</p>

<details open>
  <summary><strong>🛠️ Installation & Setup</strong></summary>
  <br>
  <p>If you see errors related to <code>SDL2/SDL.h</code>, install the development dependencies:</p>
  
  <h4>🐧 Linux (Ubuntu/Debian/Mint)</h4>
  <pre><code>sudo apt update && sudo apt install libsdl2-dev</code></pre>

  <h4>🎩 Linux (Fedora/Arch)</h4>
  <ul>
    <li><strong>Fedora:</strong> <code>sudo dnf install SDL2-devel</code></li>
    <li><strong>Arch:</strong> <code>sudo pacman -S sdl2</code></li>
  </ul>
</details>

<hr>

<h2>🏗️ Compilation Guide</h2>

<p>To compile the project correctly, you must link both the SDL2 and Math libraries:</p>

<pre><code>cc -o cube cube.c `sdl2-config --cflags --libs`</code></pre>
<pre><code>cc -o cube cube.c -lm `sdl2-config --cflags --libs`</code></pre>

<blockquote>
  <strong>⚠️ Important: The <code>-lm</code> Flag</strong><br>
  If you receive a <code>DSO missing from command line</code> or <code>undefined reference to cos/sin</code> error, it is because the Math library isn't linked. 
  <br><br>
  <em>Only include <strong>-lm</strong> when your code uses mathematical functions like <code>sin()</code>, <code>cos()</code>, <code>tan()</code>, or <code>sqrt()</code>.</em>
</blockquote>

<hr>

<h2>📅 Project Status</h2>
<ul>
  <li>✅ Setup Basic Rendering</li>
  <li>🚧 Rotating Cube Logic (In Progress)</li>
  <li>📅 Texture Mapping (Planned)</li>
</ul>

<div align="right">
  <em>Maintained by Luna</em>
</div>
