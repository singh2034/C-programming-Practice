<h1 align="center">🚀 C-Programming-Practice</h1>

<p align="center">
  <em>A collection of ongoing C projects exploring low-level graphics and logic.</em>
</p>

<hr>

<h2>🧊 Project: Rotating Cube</h2>

<p>This project renders a 3D wireframe cube in a window. It relies on the <strong>SDL2</strong> (Simple DirectMedia Layer) library for graphical output.</p>

<details open>
  <summary><strong>⚠️ Troubleshooting: "SDL.h not found"</strong></summary>
  <br>
  <p>If you see errors related to <code>SDL2/SDL.h</code>, you must install the development dependencies for your operating system:</p>
  
  <h4>🐧 Linux (Ubuntu/Debian/Mint)</h4>
  <pre><code>sudo apt update && sudo apt install libsdl2-dev</code></pre>

  <h4>🎩 Linux (Fedora/Arch)</h4>
  <ul>
    <li><strong>Fedora:</strong> <code>sudo dnf install SDL2-devel</code></li>
    <li><strong>Arch:</strong> <code>sudo pacman -S sdl2</code></li>
  </ul>

  <h4>🪟 Windows</h4>
  <blockquote>
    Windows users must manually link the SDL2 <code>.dll</code> and <code>.lib</code> files. You can find these on the 
    <a href="https://github.com/libsdl-org/SDL/releases">Official SDL GitHub</a>.
  </blockquote>
</details>

<hr>

<h2>🛠️ Compilation Guide</h2>

<p>To compile the project with the necessary libraries linked, run the following command in your terminal:</p>

<pre><code>gcc rotating-cube/cube.c -o cube -lSDL2 -lm</code></pre>

<ul>
  <li><code>-lSDL2</code>: Tells the compiler to use the SDL2 library.</li>
  <li><code>-lm</code>: Links the math library (needed for <code>sin</code> and <code>cos</code> functions).</li>
</ul>

<hr>

<h2>📅 Project Roadmap</h2>
<ul>
  <li>✅ Setup Basic Rendering</li>
  <li>🚧 Rotating Cube Logic (In Progress)</li>
  <li>📅 Texture Mapping (Planned)</li>
</ul>

<div align="right">
  <em>Maintained by Luna</em>
</div>