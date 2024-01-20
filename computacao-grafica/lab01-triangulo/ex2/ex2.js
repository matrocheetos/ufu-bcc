var gl;
var points;

var vPosition, vPosition2, vPosition3, vPosition4, vPosition5, vPosition6, vPosition7;
var bufferId, bufferId2, bufferId3, bufferId4, bufferId5, bufferId6, bufferId7;
var program;

var triangulo1 = new Float32Array([-1, -1, -1, 0, -0.75, -1]); // TRIANGLES esquerda inferior
var triangulo2 = new Float32Array([-0.7, -1, -0.7, 0, -0.3, -1]); // TRIANGLE_STRIP
// var triangulo3 = new Float32Array([-1, 1, 0, -1, 1, 1]); // TRIANGLE_FAN
var ponto = new Float32Array([0, 0, 0, 1]) // POINTS
var linha1 = new Float32Array([0, 0, 0, 1]) // LINES
var linha2 = new Float32Array([0, 0, 0, 1]) // LINE_STRIP
var linha3 = new Float32Array([0, 0, 0, 1]) // LINE_LOOP

window.onload = function init()
{
    var canvas = document.getElementById( "gl-canvas" );
    
    gl = WebGLUtils.setupWebGL( canvas );
    if ( !gl ) { alert( "WebGL isn't available" ); }

    

    //
    //  Configure WebGL
    //
    gl.viewport( 0, 0, canvas.width, canvas.height );
    gl.clearColor( 0.23, 0.22, 0.82, 1.0 );
    
    //  Load shaders and initialize attribute buffers
    
    program = initShaders( gl, "vertex-shader", "fragment-shader" );
    gl.useProgram( program );
    
    // Load the data into the GPU
    
    bufferId = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId );
    gl.bufferData( gl.ARRAY_BUFFER,triangulo1, gl.STATIC_DRAW );

    
    bufferId2 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId2 );
    gl.bufferData( gl.ARRAY_BUFFER,triangulo2, gl.STATIC_DRAW );
        
//     bufferId3 = gl.createBuffer();
//     gl.bindBuffer( gl.ARRAY_BUFFER, bufferId3 );
//     gl.bufferData( gl.ARRAY_BUFFER,triangulo3, gl.STATIC_DRAW );

    bufferId4 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId4 );
    gl.bufferData( gl.ARRAY_BUFFER,ponto, gl.STATIC_DRAW );

    bufferId5 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId5 );
    gl.bufferData( gl.ARRAY_BUFFER,linha1, gl.STATIC_DRAW );

    bufferId6 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId6 );
    gl.bufferData( gl.ARRAY_BUFFER,linha2, gl.STATIC_DRAW );

    bufferId7 = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId7 );
    gl.bufferData( gl.ARRAY_BUFFER,linha3, gl.STATIC_DRAW );

    render();
};


function render() {
    gl.clear( gl.COLOR_BUFFER_BIT );
    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId );
    vPosition = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPosition, 2, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPosition );
    gl.drawArrays( gl.TRIANGLES, 0, 3 );
    
    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId2 );
    vPosition2 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPosition2, 2, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPosition2 );
    gl.drawArrays( gl.TRIANGLE_STRIP, 0, 3 );
    
    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId3 );
    vPosition3 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPosition3, 2, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPosition3 );
    gl.drawArrays( gl.TRIANGLE_FAN, 0, 3 );

    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId4 );
    vPosition4 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPosition4, 2, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPosition4 );
    gl.drawArrays( gl.POINTS, 0, ponto.length/3 );

    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId5 );
    vPosition5 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPosition5, 2, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPosition5 );
    gl.drawArrays( gl.LINES, 0, 3 );
    
    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId6 );
    vPosition6 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPosition6, 2, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPosition6 );
    gl.drawArrays( gl.LINE_STRIP, 0, 3 );

    gl.bindBuffer( gl.ARRAY_BUFFER, bufferId7 );
    vPosition7 = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPosition7, 2, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPosition7 );
    gl.drawArrays( gl.LINE_LOOP, 0, 3 );

}
